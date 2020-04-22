#include "node.h"

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}
void list_clear(node * & head_ptr, node * & tail_ptr){
  node *p=head_ptr;
  //link != nullptr
  while(head_ptr->link()!=nullptr){
    // checks second to last null ptr
    if(p->link()->link()==nullptr) {
      // deletes the last one
      delete tail_ptr;
      // sets tail to the pervious one
      tail_ptr = p;
      // sets pervious node to last one
      tail_ptr->set_link(nullptr);
      // resets p
      p=head_ptr;
    }
    else{
      // i++
      p = p->link();
    }
  }
  // deletes first node
  delete head_ptr;
}
void list_reverse(node * & head_ptr, node * & tail_ptr){
  if(head_ptr==tail_ptr ){
    return;
  }
  else{
    node *temp = head_ptr;
    node *temp2 = tail_ptr;
    head_ptr = tail_ptr;
    tail_ptr = temp;
    temp = tail_ptr->link();
    list_reverse(temp,temp2);
    tail_ptr->link()->set_link(tail_ptr);
    tail_ptr->set_link(nullptr);

  }
}


