using System;

public class Class1
{
    #region 146_LRU缓存机制 
    /*
    运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
    获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
    写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。
    当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

    进阶:
    你是否可以在 O(1) 时间复杂度内完成这两种操作？

    示例:
    LRUCache cache = new LRUCache(2); // 缓存容量
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/lru-cache
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    */
    public class LRUCache
    {
        //Runtime: 240 ms, faster than 98.28% of C# online submissions for LRU Cache.
        //Memory Usage: 49.7 MB, less than 6.67% of C# online submissions for LRU Cache.
        public class DLinkNode
        {
            public DLinkNode front;
            public DLinkNode next;
            public int key;
            public int val;

            public DLinkNode() { }

            public DLinkNode(int k, int v)
            {
                key = k;
                val = v;
            }
        }

        // 双端链表 + 哈希表
        Dictionary<int, DLinkNode> map;
        DLinkNode first, end;
        int count;

        public LRUCache(int capacity)
        {
            map = new Dictionary<int, DLinkNode>();
            first = new DLinkNode();
            end = new DLinkNode();
            first.next = end;
            end.front = first;

            count = capacity;
        }

        public int Get(int key)
        {
            if (!map.ContainsKey(key))
            {
                return -1;
            }

            DLinkNode temp = map[key];
            RemoveNode(temp);
            MoveToHead(temp);
            return temp.val;
        }

        public void Put(int key, int value)
        {
            if (count <= 0) return;

            if (map.ContainsKey(key))
            {
                map[key].val = value; // Update value
                RemoveNode(map[key]);
                MoveToHead(map[key]);
            }
            else
            {
                if (map.Count == count)
                {
                    // 满了, 先移除链表尾部
                    DLinkNode tail = end.front;
                    map.Remove(tail.key);
                    RemoveNode(tail);
                }

                DLinkNode temp = new DLinkNode(key, value);
                map.Add(key, temp);
                MoveToHead(temp);
            }
        }

        // 将Node放置链表首部
        public void MoveToHead(DLinkNode node)
        {
            DLinkNode temp = first.next;
            first.next = node;
            node.front = first;

            node.next = temp;
            temp.front = node;
        }

        // 将节点从链表中移除
        public void RemoveNode(DLinkNode node)
        {
            DLinkNode f = node.front;
            DLinkNode n = node.next;
            f.next = n;
            n.front = f;
        }

        static void Main(string[] args)
        {
            LRUCache lru = new LRUCache(2);
            lru.Put(1, 1);
            lru.Put(2, 2);
            lru.Get(1);
            lru.Put(3, 3);
            lru.Get(2);
            lru.Put(4, 4);
            lru.Get(1);
            lru.Get(3);
            lru.Get(4);
        }
    }
    #endregion

}
