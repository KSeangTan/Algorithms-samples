using namespace std;
struct ListNode {
  ListNode *next;
  int value;

  ListNode() {
      value = 0;
      next = nullptr;
  }

  ListNode(int c): value(c), next(nullptr) {
  }

  ~ListNode() {
      if(this->next != nullptr) {
        delete this->next;
      }
      this->next = nullptr;
  }

  void insertNext(int c) {
      this->next = new ListNode(c);
  }

};

struct DoublyListNode {
  DoublyListNode *next;
  DoublyListNode *previous;
  int value;

  DoublyListNode() {
      value = 0;
      next = nullptr;
      previous = nullptr;
  }

  DoublyListNode(int c): value(c), next(nullptr), previous(nullptr) {
  }

  ~DoublyListNode() {
      if(this->next != nullptr) {
        delete this->next;
      }
      this->next = nullptr;
      this->previous = nullptr;
  }

  void insertNext(int c) {
      this->next = new DoublyListNode(c);
      this->next->previous = this;
  }

  void insertPrevious(int c) {
      DoublyListNode* p = new DoublyListNode(c);
      DoublyListNode* tmp = this->previous;
      this->previous = p;
      p->next = this;
      p->previous = tmp;
      if(tmp != nullptr)
        tmp->next = p;
  }

};

struct Deque {
    DoublyListNode *head;
    DoublyListNode *back;
    int size;
    Deque(): head(nullptr), back(nullptr), size(0) {
    
    }

    ~Deque() {
        if(this->head != nullptr) {
            delete this->head;
        }
        this->head = nullptr;
        this->back = nullptr;
    }

    void insertFront(int c) {
        if(head == nullptr) {
            head = back = new DoublyListNode(c);
        } else {
            head->insertPrevious(c);
            head = head->previous;
        }
        size++;
    }

    void insertBack(int c) {
        if(back == nullptr) {
            head = back = new DoublyListNode(c);
        } else {
            back->insertNext(c);
            back = back->next;
        }
        size++;
    }

    int getSize() {
        return size;
    }
    int getBack() {
        if (isEmpty())
            throw "Overflow Error";
        return back->value;  
    }

    int getFront() {
        if(isEmpty())
            throw "Underflow Error";
        return head->value;
    }

    bool isEmpty() {
        return (head == nullptr);
    }
    bool deleteFront() {
        if(head == nullptr)
            return false;
        DoublyListNode *p = head;
        head = head->next;
        if(head == nullptr) {
            back = nullptr;
        } else {
            head->previous = nullptr;
        }
        free(p);
        size--;
        return true;
    }

    bool deleteBack() {
        if(back == nullptr)
            return false;
        DoublyListNode *p = back;
        back = back->previous;
        if(back == nullptr) {
            head = nullptr;
        } else {
            back->next = nullptr;
        }
        free(p);
        size--;
        return true;
    } 
};

struct Stack {
    Deque node;

    int pop() {
        int i = node.getBack();
        node.deleteBack();
        return i;
    }

    void push(int c) {
        node.insertBack(c);
    }

    int size() {
        return node.size;
    }
};

struct Queue {
    Deque node;

    int deQueue() {
        int i = node.getFront();
        node.deleteFront();
        return i;
    }

    void enQueue(int c) {
        node.insertBack(c);
    }

    int size() {
        return node.size;
    }
};

