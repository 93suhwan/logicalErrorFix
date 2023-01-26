#include <bits/stdc++.h>
enum nodetype { pnode, qnode, leafnode };
enum marking { empty, partial, full };
enum print_option { option_none, option_marking, option_depth, option_src };
enum direction_type { left, right };
class Node {
 protected:
  Node *parent;
  int depth;
  nodetype type;
  marking node_mark;

 public:
  Node();
  virtual ~Node() {}
  virtual void print() = 0;
  virtual std::string print_expression(print_option m = option_none) = 0;
  virtual void update_depth() = 0;
  virtual bool less_than(Node &) = 0;
  virtual void sort() = 0;
  virtual std::string convert_to_gml(int &) = 0;
  Node *get_parent();
  int get_depth() const;
  nodetype get_type() const;
  marking get_mark() const;
  virtual void unmark() = 0;
  void set_parent(Node *);
};
bool compare_marking(Node *, Node *);
namespace custom {
bool contains(std::vector<int> vec, int v);
};
Node::Node() {
  parent = NULL;
  depth = 0;
  node_mark = empty;
  type = pnode;
}
void Node::print() {
  printf("Node addr: %p\n", this);
  if (parent == NULL) {
    printf("parent addr: NULL\n");
  } else {
    printf("parent addr: %p \n", parent);
  }
  switch (node_mark) {
    case full:
      printf("mark: full\n");
      break;
    case empty:
      printf("mark: empty\n");
      break;
    case partial:
      printf("mark: partial\n");
      break;
  }
  printf("depth = %d\n", depth);
}
Node *Node::get_parent() { return parent; }
int Node::get_depth() const { return depth; }
nodetype Node::get_type() const { return type; }
marking Node::get_mark() const { return node_mark; }
void Node::set_parent(Node *p) { parent = p; }
bool compare_marking(Node *first, Node *second) {
  marking a = first->get_mark();
  marking b = second->get_mark();
  if (a == b) {
    return false;
  } else if (b == full) {
    return true;
  } else if (b == partial) {
    if (a == full) {
      return false;
    } else {
      return true;
    }
  } else {
    return false;
  }
}
bool custom::contains(std::vector<int> vec, int v) {
  for (size_t i = 0; i < vec.size(); ++i) {
    if (vec[i] == v) {
      return true;
    }
  }
  return false;
}
std::string Node::convert_to_gml(int &id) {
  ++id;
  std::string result = "node [\nid ";
  result += std::to_string(id);
  result += "\ngraphics [\nw 20.0\n";
  result += "h 20.0\n]\n";
  return result;
}
class Leaf : public Node {
 private:
  int value;
  int source;
  Leaf **leaf_list_ptr;
  bool less_than(Node &);
  void sort() {}

 public:
  Leaf(Node *, int, std::list<Leaf *> &, int src = -1);
  Leaf(int, std::list<Leaf *> &, int src = -1);
  virtual ~Leaf();
  void print();
  std::string print_expression(print_option m = option_none);
  std::string convert_to_gml(int &);
  void mark();
  void update_depth();
  void unmark();
  int get_value();
  int get_source();
};
static bool leaks = true;
static int buildcount = 0;
using std::cerr;
using std::endl;
Leaf::Leaf(Node *p, int v, std::list<Leaf *> &leaflist, int src) : Node() {
  if (leaks) {
    ++buildcount;
  }
  parent = p;
  value = v;
  source = src;
  depth = p->get_depth() + 1;
  leaflist.push_back(this);
  leaf_list_ptr = &leaflist.back();
  type = leafnode;
}
Leaf::Leaf(int v, std::list<Leaf *> &leaflist, int src) : Node() {
  if (leaks) {
    ++buildcount;
  }
  value = v;
  source = src;
  leaflist.push_back(this);
  leaf_list_ptr = &leaflist.back();
  type = leafnode;
}
Leaf::~Leaf() {
  if (leaks) {
    --buildcount;
  }
  parent = NULL;
  if (leaf_list_ptr != NULL) {
    *leaf_list_ptr = NULL;
    leaf_list_ptr = NULL;
  }
}
bool Leaf::less_than(Node &other) {
  if (Leaf *lf = dynamic_cast<Leaf *>(&other)) {
    if (lf->value > value) {
      return true;
    }
  } else {
    return true;
  }
  return false;
}
void Leaf::print() {
  printf("========= node-type: LEAF NODE ======== \n");
  Node::print();
  printf("value: %d\n\n", value);
}
void Leaf::mark() { node_mark = full; }
int Leaf::get_value() { return value; }
void Leaf::unmark() { node_mark = empty; }
int Leaf::get_source() { return source; }
std::string Leaf::print_expression(print_option print_mark) {
  std::string result = "";
  switch (print_mark) {
    case option_marking:
      switch (node_mark) {
        case full:
          result += "f:";
          break;
        case partial:
          result += "p:";
          break;
        case empty:
          result += "e:";
          break;
      }
      break;
    case option_depth:
      result += std::to_string(depth) + ":";
      ;
      break;
    case option_src:
      result += std::to_string(source) + ":";
      break;
    default:
      break;
  }
  result += std::to_string(value);
  return result;
}
void Leaf::update_depth() {
  if (parent == NULL) {
    depth = 0;
  } else {
    depth = parent->get_depth() + 1;
  }
}
std::string Leaf::convert_to_gml(int &id) {
  std::string result = Node::convert_to_gml(id);
  result += "label \"";
  result += std::to_string(value);
  result += "\"\n]\n";
  return result;
}
class PQnode : public Node {
 private:
  std::list<Node *> children;
  bool flipped;
  bool reduce_proot();
  bool reduce_qroot();
  bool qreduce(direction_type);
  bool preduce(direction_type);
  bool reduce(direction_type);
  Node *group_children(std::list<Node *> &);
  size_t grab_marks(std::list<Node *>::iterator &, marking,
                    std::list<Node *> &);
  bool promote_partial_children(std::list<Node *>::iterator &, direction_type);
  void pop_children(std::list<Node *> &kids);
  size_t skip_marks(std::list<Node *>::iterator &, marking);
  bool less_than(Node &);

 public:
  PQnode();
  PQnode(std::vector<int>, std::list<Leaf *> &, nodetype t = pnode);
  PQnode(std::vector<int>, std::list<Leaf *> &, int src, nodetype t = pnode);
  virtual ~PQnode();
  void sort_children();
  Node *pop_child();
  size_t count_children();
  bool mark();
  void unmark();
  bool condense_and_replace(Node *, std::list<int> &);
  bool link_child(Node *, direction_type dir = right);
  void update_depth();
  bool reduce();
  void set_type(nodetype t);
  void sort();
  std::string print_expression(print_option m = option_none);
  void print();
  std::string convert_to_gml(int &);
};
namespace custom {
void print(std::list<int>);
void print(std::vector<int>);
bool compare(std::string s1, std::string s2);
};  // namespace custom
static bool follow = false;
static bool debug = false;
static int builtcount = 0;
using std::cerr;
using std::cout;
using std::endl;
PQnode::PQnode() : Node() {
  builtcount++;
  type = pnode;
  flipped = false;
}
PQnode::PQnode(std::vector<int> leaves, std::list<Leaf *> &leaflist, nodetype t)
    : Node() {
  builtcount++;
  int src = -1;
  for (size_t i = 0; i < leaves.size(); ++i) {
    Leaf *lf = new Leaf(this, leaves[i], leaflist, src);
    children.push_back(lf);
  }
  set_type(t);
  flipped = false;
}
PQnode::PQnode(std::vector<int> leaves, std::list<Leaf *> &leaflist, int src,
               nodetype t)
    : Node() {
  builtcount++;
  for (size_t i = 0; i < leaves.size(); ++i) {
    Leaf *lf = new Leaf(this, leaves[i], leaflist, src);
    children.push_back(lf);
  }
  set_type(t);
  flipped = false;
}
PQnode::~PQnode() {
  --builtcount;
  if (!children.empty()) {
    auto it = children.begin();
    while (it != children.end()) {
      Node *curr = *it;
      it = children.erase(it);
      delete curr;
    }
  }
}
bool PQnode::less_than(Node &other) {
  if (PQnode *pq = dynamic_cast<PQnode *>(&other)) {
    if (pq->type != type) {
      if (type == pnode) {
        return false;
      } else {
        return true;
      }
    } else {
      if (count_children() > pq->count_children()) {
        return false;
      } else if (count_children() < pq->count_children()) {
        return true;
      } else {
        auto itt = children.begin();
        auto ito = (pq->children).begin();
        while (itt != children.end() && ito != ((pq->children).end())) {
          if (!(*itt)->less_than(**ito)) {
            return false;
          }
          ++itt;
          ++ito;
        }
        return true;
      }
    }
  } else {
    return false;
  }
}
void PQnode::sort() {
  for (auto it = children.begin(); it != children.end(); ++it) {
    (*it)->sort();
  }
  if (type == pnode) {
    bool swapped = true;
    auto end = children.end();
    while (swapped && end != children.begin()) {
      swapped = false;
      auto prev = children.begin();
      auto curr = children.begin();
      ++curr;
      while (curr != end) {
        if ((*curr)->less_than(**prev)) {
          Node *tmp = *prev;
          *prev = *curr;
          *curr = tmp;
          swapped = true;
        }
        ++prev;
        ++curr;
      }
      --end;
    }
  } else if (type == qnode) {
    Node *st = children.front();
    Node *end = children.back();
    if (end->less_than(*st)) {
      children.reverse();
      flipped = !flipped;
    }
  }
}
void PQnode::print() {
  printf("+++++++++++++ node-type: %s  +++++++++++\n",
         (type == pnode) ? "P" : "Q");
  Node::print();
  printf("num children: %lu ... \n\n", children.size());
  for (std::list<Node *>::iterator it = children.begin(); it != children.end();
       ++it) {
    (*it)->print();
  }
}
size_t PQnode::skip_marks(std::list<Node *>::iterator &itr, marking m) {
  size_t count = 0;
  while (itr != children.end()) {
    if ((*itr)->get_mark() == m) {
      ++count;
      ++itr;
    } else {
      return count;
    }
  }
  return count;
}
size_t PQnode::grab_marks(std::list<Node *>::iterator &itr, marking m,
                          std::list<Node *> &tmplist) {
  size_t count = 0;
  while (itr != children.end()) {
    Node *temp = (*itr);
    if (temp->get_mark() == m) {
      tmplist.push_back(temp);
      ++count;
      ++itr;
    } else {
      return count;
    }
  }
  return count;
}
bool PQnode::mark() {
  size_t ecount = 0;
  size_t pcount = 0;
  size_t fcount = 0;
  std::list<Node *>::iterator it;
  if (type == pnode) {
    sort_children();
    it = children.begin();
    ecount += skip_marks(it, empty);
    pcount += skip_marks(it, partial);
    fcount += skip_marks(it, full);
  } else {
    it = children.begin();
    ecount += skip_marks(it, empty);
    pcount += skip_marks(it, partial);
    fcount += skip_marks(it, full);
    pcount += skip_marks(it, partial);
    ecount += skip_marks(it, empty);
  }
  if (it != children.end()) {
    return false;
  }
  if (pcount > 2) {
    return false;
  } else if (pcount > 0) {
    node_mark = partial;
  } else if (fcount > 0 && ecount > 0) {
    node_mark = partial;
  } else if (fcount > 0) {
    node_mark = full;
  } else {
    node_mark = empty;
  }
  return true;
}
void PQnode::sort_children() {
  if (type == qnode) {
    std::list<Node *>::iterator it = children.begin();
    while (it != children.end()) {
      size_t ecount = skip_marks(it, empty);
      skip_marks(it, partial);
      size_t fcount = skip_marks(it, full);
      size_t p2count = skip_marks(it, partial);
      size_t e2count = skip_marks(it, empty);
      if (ecount > 0) {
        return;
      } else if (e2count > 0) {
        children.reverse();
        flipped = !flipped;
      } else if (fcount > 0 && p2count > 0) {
        children.reverse();
        flipped = !flipped;
      }
    }
  } else {
    children.sort(compare_marking);
  }
}
void PQnode::unmark() {
  if (node_mark == empty) {
    return;
  }
  node_mark = empty;
  for (auto it = children.begin(); it != children.end(); ++it) {
    (*it)->unmark();
  }
}
int answer = 1;
std::string PQnode::print_expression(print_option print_mark) {
  std::string result = "";
  switch (print_mark) {
    case option_marking:
      switch (node_mark) {
        case full:
          result += "f:";
          break;
        case empty:
          result += "e:";
          break;
        case partial:
          result += "p:";
          break;
      }
      break;
    case option_depth:
      result += std::to_string(depth) + ":";
      break;
    default:
      break;
  }
  bool tps = 0;
  if (type == qnode) {
    result += "[";
  } else {
    tps = 1;
    result += "{";
  }
  int counter = 0;
  for (auto it = children.begin(); it != children.end(); ++it) {
    counter++;
    result += " ";
    result += (*it)->print_expression(print_mark);
    result += " ";
  }
  if (tps == 1) {
    for (int i = 1; i <= counter; i++)
      answer = (answer * (long long)i) % 998244353;
  } else {
    if (counter > 1) answer *= 2;
  }
  if (type == qnode) {
    result += "]";
  } else {
    result += "}";
  }
  return result;
}
bool PQnode::reduce() {
  if (debug) {
    cerr << "reducing the node: " << print_expression(option_marking) << endl;
  }
  if (type == pnode) {
    return reduce_proot();
  } else {
    return reduce_qroot();
  }
}
bool PQnode::reduce_proot() {
  if (follow) {
    cerr << "PQnode::reduce_proot()" << endl;
  }
  if (debug) {
    cerr << print_expression() << endl;
  }
  std::list<Node *> empty_list;
  std::list<Node *> partials_list;
  std::list<Node *> sec_partials_list;
  std::list<Node *> full_list;
  sort_children();
  auto it = children.begin();
  size_t ecount = grab_marks(it, empty, empty_list);
  if (it != children.end()) {
    PQnode *ch = dynamic_cast<PQnode *>(*it);
    if (ch && (*it)->get_mark() == partial) {
      if (ch->reduce(right)) {
        ch->pop_children(partials_list);
      } else {
        return false;
      }
      it = children.erase(it);
      delete ch;
    }
  }
  if (it != children.end()) {
    PQnode *ch = dynamic_cast<PQnode *>(*it);
    if (ch && (*it)->get_mark() == partial) {
      if (ch->reduce(left)) {
        ch->pop_children(sec_partials_list);
      } else {
        return false;
      }
      it = children.erase(it);
      delete ch;
    }
  }
  grab_marks(it, full, full_list);
  if (it != children.end()) {
    partials_list.clear();
    sec_partials_list.clear();
    return false;
  }
  children.clear();
  children.splice(children.end(), empty_list);
  empty_list.clear();
  if (partials_list.empty()) {
    link_child(group_children(full_list));
    return true;
  }
  if (ecount > 0) {
    PQnode *qtemp = new PQnode();
    for (it = partials_list.begin(); it != partials_list.end(); ++it) {
      qtemp->link_child((*it));
    }
    partials_list.clear();
    if (debug) {
      cerr << "qtemp: added the first set of partials: "
           << qtemp->print_expression() << endl;
    }
    qtemp->link_child(group_children(full_list));
    if (debug) {
      cerr << "qtemp: added the fulls: " << qtemp->print_expression() << endl;
    }
    for (it = sec_partials_list.begin(); it != sec_partials_list.end(); ++it) {
      qtemp->link_child((*it));
    }
    sec_partials_list.clear();
    if (debug) {
      cerr << "qtemp: added the second set of partials: "
           << qtemp->print_expression() << endl;
    }
    qtemp->set_type(qnode);
    link_child(qtemp);
    if (!qtemp->mark()) {
      if (debug) {
        cerr << "unable to mark the new node: "
             << qtemp->print_expression(option_marking) << endl;
      }
      return false;
    }
  } else {
    for (it = partials_list.begin(); it != partials_list.end(); ++it) {
      link_child((*it));
    }
    partials_list.clear();
    for (it = full_list.begin(); it != full_list.end(); ++it) {
      link_child((*it));
    }
    full_list.clear();
    for (it = sec_partials_list.begin(); it != sec_partials_list.end(); ++it) {
      link_child((*it));
    }
    sec_partials_list.clear();
    set_type(qnode);
  }
  update_depth();
  return true;
}
void PQnode::pop_children(std::list<Node *> &kids) {
  Node *temp = pop_child();
  while (temp != NULL) {
    kids.push_back(temp);
    temp = pop_child();
  }
}
bool PQnode::reduce_qroot() {
  if (follow) {
    cerr << "PQnode::reduce_qroot()" << endl;
  }
  sort_children();
  auto it = children.begin();
  skip_marks(it, empty);
  if (!promote_partial_children(it, right)) {
    return false;
  }
  skip_marks(it, full);
  if (!promote_partial_children(it, left)) {
    return false;
  }
  update_depth();
  return true;
}
bool PQnode::promote_partial_children(std::list<Node *>::iterator &it,
                                      direction_type dir) {
  if (it != children.end()) {
    PQnode *curr = dynamic_cast<PQnode *>(*it);
    if (curr != NULL && curr->get_mark() == partial) {
      if (curr->reduce(dir)) {
        it = children.erase(it);
        Node *temp = curr->pop_child();
        while (temp != NULL) {
          children.insert(it, temp);
          temp->set_parent(this);
          temp->update_depth();
          temp = curr->pop_child();
        }
        delete curr;
        curr = NULL;
      } else {
        return false;
      }
    }
  }
  return true;
}
bool PQnode::reduce(direction_type dir) {
  if (type == pnode) {
    return preduce(dir);
  } else {
    return qreduce(dir);
  }
}
bool PQnode::preduce(direction_type dir) {
  if (follow) {
    cerr << "PQnode::preduce(bool direction)" << endl;
  }
  if (node_mark == full) {
    return true;
  } else if (node_mark == empty) {
    return true;
  }
  std::list<Node *> empty_list;
  std::list<Node *> partials_list;
  std::list<Node *> full_list;
  sort_children();
  std::list<Node *>::iterator it = children.begin();
  grab_marks(it, empty, empty_list);
  if (it != children.end()) {
    PQnode *ch = dynamic_cast<PQnode *>(*it);
    if (ch && (*it)->get_mark() == partial) {
      if (ch->reduce(dir)) {
        Node *temp = ch->pop_child();
        while (temp != NULL) {
          partials_list.push_back(temp);
          temp = ch->pop_child();
        }
      } else {
        return false;
      }
      it = children.erase(it);
      delete ch;
    }
  }
  grab_marks(it, full, full_list);
  if (it != children.end()) {
    return false;
  }
  children.clear();
  for (it = partials_list.begin(); it != partials_list.end(); ++it) {
    link_child(*it);
  }
  partials_list.clear();
  link_child(group_children(full_list), dir);
  if (dir == right) {
    link_child(group_children(empty_list), left);
  } else {
    link_child(group_children(empty_list), right);
  }
  set_type(qnode);
  return true;
}
bool PQnode::qreduce(direction_type dir) {
  if (follow || debug) {
    cerr << "PQnode::qreduce(bool direction)" << endl;
  }
  if (debug) {
    cerr << this << " qreduce on: " << print_expression(option_marking) << endl;
    if (dir == right) {
      cerr << "RIGHT" << endl;
    } else {
      cerr << "LEFT" << endl;
    }
  }
  std::list<Node *> empty_list;
  std::list<Node *> partials_list;
  std::list<Node *> fulls_list;
  size_t pcount = 0;
  if (node_mark != partial) {
    return true;
  }
  sort_children();
  auto it = children.begin();
  grab_marks(it, empty, empty_list);
  pcount = grab_marks(it, partial, partials_list);
  grab_marks(it, full, fulls_list);
  if (it != children.end() || pcount > 1) {
    return false;
  }
  children.clear();
  if (debug) {
    cerr << this
         << " after clearing children: " << print_expression(option_marking)
         << endl;
  }
  if (pcount == 1) {
    PQnode *ptemp = dynamic_cast<PQnode *>(partials_list.front());
    partials_list.pop_front();
    ptemp->reduce(dir);
    ptemp->pop_children(partials_list);
    delete ptemp;
  }
  if (dir == right) {
    for (auto k = empty_list.begin(); k != empty_list.end(); ++k) {
      link_child(*k);
    }
    if (debug) {
      cerr << this << " after adding empty children: "
           << print_expression(option_marking) << endl;
    }
    for (auto k = partials_list.begin(); k != partials_list.end(); ++k) {
      link_child(*k);
    }
    if (debug) {
      cerr << this << " after adding partial children: "
           << print_expression(option_marking) << endl;
    }
    for (auto k = fulls_list.begin(); k != fulls_list.end(); ++k) {
      link_child(*k);
    }
    if (debug) {
      cerr << this << " after adding full children: "
           << print_expression(option_marking) << endl;
    }
  } else {
    for (auto k = fulls_list.rbegin(); k != fulls_list.rend(); ++k) {
      link_child(*k);
    }
    if (debug) {
      cerr << this << " after adding full children: "
           << print_expression(option_marking) << endl;
    }
    for (auto k = partials_list.begin(); k != partials_list.end(); ++k) {
      link_child(*k);
    }
    if (debug) {
      cerr << this << " after adding partial children: "
           << print_expression(option_marking) << endl;
    }
    for (auto k = empty_list.rbegin(); k != empty_list.rend(); ++k) {
      link_child(*k);
    }
    if (debug) {
      cerr << this << " after adding empty children: "
           << print_expression(option_marking) << endl;
    }
  }
  return true;
}
Node *PQnode::group_children(std::list<Node *> &group) {
  if (follow) {
    cerr << "PQnode::group_children(std::list<Node*> group)" << builtcount
         << endl;
  }
  if (group.empty()) {
    return NULL;
  } else if (group.size() == 1) {
    Node *temp = group.front();
    group.pop_front();
    return temp;
  } else {
    PQnode *temp = new PQnode();
    for (auto it = group.begin(); it != group.end(); ++it) {
      temp->link_child(*it);
    }
    group.clear();
    if (!temp->mark()) {
      delete temp;
      return NULL;
    }
    return temp;
  }
}
bool PQnode::link_child(Node *child, direction_type dir) {
  if (follow) {
    cerr << "PQnode::link_child(Node *child)" << builtcount << endl;
  }
  if (child == NULL) {
    return false;
  }
  if (children.empty() || dir == right) {
    child->set_parent(this);
    children.push_back(child);
    child->update_depth();
  } else {
    child->set_parent(this);
    children.push_front(child);
    child->update_depth();
  }
  return true;
}
void PQnode::update_depth() {
  if (parent == NULL) {
    if (depth == 0) {
      return;
    }
    depth = 0;
  } else {
    if (depth == parent->get_depth() + 1) {
      return;
    }
    depth = parent->get_depth() + 1;
  }
  for (std::list<Node *>::iterator it = children.begin(); it != children.end();
       ++it) {
    (*it)->update_depth();
  }
}
Node *PQnode::pop_child() {
  if (children.empty()) {
    return NULL;
  } else {
    Node *temp = children.front();
    children.pop_front();
    temp->set_parent(NULL);
    return temp;
  }
}
size_t PQnode::count_children() { return children.size(); }
void PQnode::set_type(nodetype t) {
  if (t == qnode && count_children() > 2) {
    type = qnode;
  } else {
    type = pnode;
  }
}
bool PQnode::condense_and_replace(Node *child, std::list<int> &source_list) {
  if (follow) {
    cerr << "PQnode::condense_and_replace(Node *child): #" << builtcount
         << endl;
  }
  if (child == NULL) {
    cerr << "ERROR condense_and_replace: cannot replace with a null" << endl;
    return false;
  }
  std::list<Node *>::iterator it = children.begin();
  while (it != children.end()) {
    if ((*it)->get_mark() == full) {
      break;
    }
    ++it;
  }
  while (it != children.end()) {
    if ((*it)->get_mark() == full) {
      Node *temp = *it;
      it = children.erase(it);
      delete temp;
    } else {
      break;
    }
  }
  children.insert(it, child);
  child->set_parent(this);
  child->update_depth();
  return true;
}
void custom::print(std::list<int> target) {
  for (auto it = target.begin(); it != target.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}
void custom::print(std::vector<int> target) {
  for (auto it = target.begin(); it != target.end(); ++it) {
    cout << *it << " ";
  }
}
bool custom::compare(std::string s1, std::string s2) {
  auto a = s1.begin();
  auto b = s2.begin();
  while (a != s1.end()) {
    if ((*a) != ' ') {
      while (b != s2.end()) {
        if ((*b) != ' ') {
          if ((*b) == (*a)) {
            ++b;
            break;
          } else {
            return false;
          }
        }
        ++b;
      }
    }
    ++a;
  }
  return true;
}
std::string PQnode::convert_to_gml(int &id) {
  std::string result = Node::convert_to_gml(id);
  int curr_id = id;
  if (type == pnode) {
    result += "label \"P\"\n";
  } else {
    result += "label \"Q\"\n";
  }
  result += "]\n";
  for (auto it = children.begin(); it != children.end(); ++it) {
    result += "edge [\nsource ";
    result += std::to_string(curr_id);
    result += "\ntarget ";
    result += std::to_string(id + 1);
    result += "\n]\n";
    result += (*it)->convert_to_gml(id);
  }
  return result;
}
class Node;
class PQTree {
 private:
  int stage;
  Leaf *special_leaf;
  PQnode *root;
  std::list<Leaf *> leaflist;
  Node *build_from_expr(std::string &expr, size_t &i);
  PQnode *mark(std::vector<int> values);
  void add_unique_by_depth(PQnode *p, std::list<PQnode *> &parents);
  std::list<Leaf *> mark_pertinent(std::vector<int> values);
  bool replace_full_with(Node *, std::list<int> &);
  PQnode *reduce(std::vector<int>);
  std::list<Leaf *> get_pertinent();
  PQnode *find_full_subroot();

 public:
  PQTree();
  PQTree(std::string);
  PQTree(std::vector<int>, int src = -1);
  virtual ~PQTree();
  void print();
  std::string print_expression(print_option p = option_none);
  void print_leaflist(bool detail = false);
  std::string convert_to_gml();
  bool reduce_and_replace(int, std::vector<int>);
  bool reduce_and_replace(int, std::vector<int>, std::list<int> &);
  bool set_consecutive(std::vector<int>);
  size_t get_leaflist_size();
  bool equivalent(PQTree &);
};
static bool follow_pq = false;
static bool debug_pq = false;
static bool leaks_pq = false;
static int buildcount_pq = 0;
static std::string string_marking[] = {"empty", "partial", "full"};
using std::cerr;
using std::cout;
using std::endl;
PQTree::PQTree() {
  if (leaks) {
    cerr << "PQTree++ " << ++buildcount << endl;
  }
  root = NULL;
  stage = 0;
}
PQTree::PQTree(std::vector<int> leaves, int src) {
  if (leaks) {
    cerr << "PQTree++ " << ++buildcount << endl;
  }
  root = new PQnode(leaves, leaflist, src);
  stage = 0;
}
PQTree::PQTree(std::string expr) {
  size_t i = 0;
  if (leaks) {
    cerr << "PQTree++ " << ++buildcount << endl;
  }
  if (PQnode *tmp = dynamic_cast<PQnode *>(build_from_expr(expr, i))) {
    root = tmp;
  } else {
    root = NULL;
    cerr << "cannot initialize a pq tree with an invalid expression" << endl;
    exit(1);
  }
  stage = 0;
}
PQTree::~PQTree() {
  if (leaks) {
    cerr << "PQTree-- " << --buildcount << endl;
  }
  delete root;
  root = NULL;
}
void PQTree::print() {
  if (root == NULL) {
    cerr << "Empty tree" << endl;
  } else {
    root->print();
  }
}
bool PQTree::reduce_and_replace(int v, std::vector<int> tree_in) {
  std::list<int> sources;
  return reduce_and_replace(v, tree_in, sources);
}
bool PQTree::reduce_and_replace(int v, std::vector<int> tree_in,
                                std::list<int> &sources) {
  if (follow || debug) {
    cerr << "PQTree::reduce_and_replace(int value, std::vector<int> tree_in)"
         << endl;
  }
  std::vector<int> values;
  values.push_back(v);
  PQnode *subroot = reduce(values);
  if (debug && subroot != NULL) {
    cerr << "current tree: " << print_expression(option_marking) << endl;
    cerr << "pertinent subroot: " << subroot->print_expression(option_marking)
         << endl;
  }
  if (subroot == NULL) {
    if (follow || debug) {
      cerr << print_expression()
           << "; could not find the appropriate subroot. reduce failed" << endl;
    }
    return false;
  }
  Node *child;
  if (tree_in.size() == 1) {
    child = new Leaf(tree_in[0], leaflist, v);
  } else {
    child = new PQnode(tree_in, leaflist, v);
  }
  if (!replace_full_with(child, sources)) {
    delete child;
    child = NULL;
    return false;
  }
  subroot->unmark();
  return true;
}
PQnode *PQTree::reduce(std::vector<int> values) {
  if (follow) {
    printf("PQTree::reduce(int value)\n");
  }
  PQnode *subroot = mark(values);
  if (follow) {
    cerr << "PQTree::reduce(int value). marked as "
         << print_expression(option_marking) << endl;
  }
  if (subroot != NULL) {
    if (debug) {
      cerr << "pertinent subroot before reduce: "
           << subroot->print_expression(option_marking) << endl;
    }
    if (subroot->get_mark() == full) {
      return subroot;
    } else if (subroot->reduce()) {
      return subroot;
    }
  } else {
    if (debug) {
      cerr << "pertinent subroot not found, could be invalid leaf values"
           << endl;
    }
  }
  return NULL;
}
bool PQTree::set_consecutive(std::vector<int> values) {
  if (follow) {
    printf("PQTree::set_consecutive(std::vector<int> values)\n");
  }
  PQnode *subroot = reduce(values);
  if (subroot == NULL) {
    return false;
  }
  subroot->unmark();
  return true;
}
bool PQTree::replace_full_with(Node *child, std::list<int> &sources) {
  if (follow) {
    printf("PQTree::replace_full_with(Node *child)\n");
  }
  if (child == NULL) {
    return false;
  }
  PQnode *parent = find_full_subroot();
  if (parent == NULL) {
    fprintf(stderr, "could not find the full subroot to replace\n");
    return false;
  }
  if (!parent->condense_and_replace(child, sources)) {
    fprintf(stderr, "condense failed\n");
    return false;
  }
  if (parent->count_children() < 3) {
    parent->set_type(pnode);
  }
  return true;
}
PQnode *PQTree::mark(std::vector<int> v) {
  if (follow) {
    printf("PQTree::mark(vector<int> v)\n");
  }
  std::list<Leaf *> fulls = mark_pertinent(v);
  std::list<PQnode *> partials;
  for (std::list<Leaf *>::iterator k = fulls.begin(); k != fulls.end(); ++k) {
    PQnode *p = dynamic_cast<PQnode *>((*k)->get_parent());
    if (p == NULL) {
      return NULL;
    }
    add_unique_by_depth(p, partials);
  }
  fulls.clear();
  while (partials.size() > 1) {
    PQnode *curr = partials.front();
    if (!(curr->mark())) {
      return NULL;
    }
    if (PQnode *p = dynamic_cast<PQnode *>(curr->get_parent())) {
      partials.pop_front();
      add_unique_by_depth(p, partials);
    } else {
      partials.pop_front();
    }
  }
  if (!partials.empty() && (partials.front()->mark())) {
    return partials.front();
  }
  return NULL;
}
PQnode *PQTree::find_full_subroot() {
  if (follow) {
    printf("PQTree::find_full_subroot)\n");
  }
  if (debug) {
    cerr << "find_full_subroot(): current tree: "
         << print_expression(option_marking) << endl;
  }
  std::list<Leaf *> fulls = get_pertinent();
  std::list<PQnode *> parents;
  for (auto k = fulls.begin(); k != fulls.end(); ++k) {
    PQnode *p = dynamic_cast<PQnode *>((*k)->get_parent());
    add_unique_by_depth(p, parents);
  }
  fulls.clear();
  while (parents.size() > 1) {
    PQnode *curr = parents.front();
    PQnode *p = dynamic_cast<PQnode *>(curr->get_parent());
    parents.pop_front();
    add_unique_by_depth(p, parents);
  }
  if (!parents.empty()) {
    return parents.front();
  }
  return NULL;
}
void PQTree::add_unique_by_depth(PQnode *p, std::list<PQnode *> &partials) {
  bool found = false;
  if (partials.empty()) {
    partials.push_back(p);
    found = true;
  } else {
    for (std::list<PQnode *>::iterator it = partials.begin();
         it != partials.end() && !found; ++it) {
      if (p->get_depth() <= (*it)->get_depth()) {
        if (p == (*it)) {
          found = true;
        }
      } else {
        found = true;
        partials.insert(it, p);
      }
    }
  }
  if (!found) {
    partials.push_back(p);
  }
}
std::string PQTree::print_expression(print_option p) {
  std::string result = root->print_expression(p);
  return result;
}
Node *PQTree::build_from_expr(std::string &expr, size_t &i) {
  if (follow) {
    printf("PQTree::build_from_expr(std::string const expr, int &i)\n");
  }
  int state = 0;
  bool reading = true;
  bool isqnode = false;
  PQnode *rt = NULL;
  Leaf *lf = NULL;
  while (reading && i < expr.length()) {
    switch (state) {
      case 0:
        if (isspace(expr[i])) {
          ++i;
        } else if (expr[i] == '{' || expr[i] == '[') {
          if (expr[i] == '[') {
            isqnode = true;
          }
          state = 1;
          ++i;
          rt = new PQnode();
        } else {
          return NULL;
        }
        break;
      case 1:
        if (isspace(expr[i])) {
          ++i;
        } else if (expr[i] == '{' || expr[i] == '[') {
          Node *child = build_from_expr(expr, i);
          rt->link_child(child);
          ++i;
        } else if (expr[i] == '}' || expr[i] == ']') {
          reading = false;
        } else if (isdigit(expr[i])) {
          std::string num = "";
          while (i < expr.length() && expr[i] != ' ' && expr[i] != ']' &&
                 expr[i] != '}') {
            num += expr[i++];
          }
          lf = new Leaf(rt, atoi(num.c_str()), leaflist);
          rt->link_child(lf);
        }
        break;
      default:
        return NULL;
    }
  }
  if (rt != NULL) {
    if (isqnode && rt->count_children() > 2) {
      rt->set_type(qnode);
    } else if (rt->count_children() == 1) {
      delete rt;
      return lf;
    }
  }
  return rt;
}
std::list<Leaf *> PQTree::mark_pertinent(std::vector<int> vec) {
  if (follow) {
    printf("PQTree::mark_pertinent(std::vector<int> vec)\n");
  }
  std::list<Leaf *> fulls;
  std::list<Leaf *>::iterator it = leaflist.begin();
  while (it != leaflist.end()) {
    if ((*it) == NULL) {
      it = leaflist.erase(it);
    } else {
      if (custom::contains(vec, (*it)->get_value())) {
        (*it)->mark();
        fulls.push_back((*it));
      }
      ++it;
    }
  }
  return fulls;
}
std::list<Leaf *> PQTree::get_pertinent() {
  if (follow) {
    printf("PQTree::get_pertinent()\n");
  }
  std::list<Leaf *> fulls;
  std::list<Leaf *>::iterator it = leaflist.begin();
  while (it != leaflist.end()) {
    if ((*it) == NULL) {
      it = leaflist.erase(it);
    } else {
      if ((*it)->get_mark() == full) {
        fulls.push_back((*it));
      }
      ++it;
    }
  }
  return fulls;
}
size_t PQTree::get_leaflist_size() { return leaflist.size(); }
bool PQTree::equivalent(PQTree &other) {
  root->sort();
  (other.root)->sort();
  return custom::compare(print_expression(), other.print_expression());
}
void PQTree::print_leaflist(bool mark) {
  for (auto it = leaflist.begin(); it != leaflist.end(); ++it) {
    if (*it == NULL) {
      printf("NULL ");
    } else {
      if (mark) {
        cout << string_marking[(*it)->get_mark()] << ":" << (*it)->get_value()
             << endl;
      } else {
        printf("%d ", (*it)->get_value());
      }
    }
  }
  printf("\n");
}
std::string PQTree::convert_to_gml() {
  int id = 0;
  std::string result = "graph [\n";
  result += root->convert_to_gml(id);
  result += "]\n";
  return result;
}
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> o(n);
  iota(o.begin(), o.end(), 1);
  PQTree tree{o};
  vector<vector<int>> ddd;
  for (size_t i = 0; i < m; ++i) {
    vector<int> g;
    int k;
    cin >> k;
    g.resize(k);
    for (int &j : g) cin >> j;
    ddd.push_back(g);
  }
  for (auto g : ddd) {
    if (!tree.set_consecutive(g)) {
      cout << 0 << '\n';
      return 0;
    }
  }
  string s = tree.print_expression();
  cout << answer;
}
