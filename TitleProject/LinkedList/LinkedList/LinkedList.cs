using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList.LinkedList
{
    class Linked<T>
    {
        public Node head;

        public int Lenght
        {
            get
            {
                if (head == null)
                {
                    return 0;
                }
                else
                {
                    Node target = head;
                    int num = 1;
                    while (target.next != null)
                    {
                        target = target.next;
                        num++;
                    }
                    return num;
                }
            }
        }

        public Linked()
        {
            head = null;
        }

        public Linked(T data)
        {
            head = new Node(data);
        }

        // 添加数据到末尾
        public void Add(T data)
        {
            if (head == null)
            {
                head = new Node(data);
            }
            else
            {
                Node target = head;
                while (target.next != null)
                {
                    target = target.next;
                }

                target.next = new Node(data);
            }
        }

        // 删除一个节点
        public bool Delete(Node node)
        {
            if (head == null)
            {
                return false;
            }
            else
            {
                if (head == node)
                {
                    if (head.next != null)
                    {
                        head = head.next;
                        return true;
                    }
                }
                else
                {
                    Node target = head;
                    while (target.next != null)
                    {
                        if (target.next == node)
                        {
                            target.next = target.next.next;
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        public class Node
        {
            public T data;

            public Node next;

            public Node(T data)
            {
                this.data = data;
            }
        }
    }

    // 链表
    /*
    public class Node<TD>
    {
        public TD data;

        public Node<TD> next;

        public Node(TD data)
        {
            this.data = data;
        }
    }
    */

    // 双链表
    /*
    class Node
    {
        public T data;

        public Node next;

        public Node before;
    }
    */
}
