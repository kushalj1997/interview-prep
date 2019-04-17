# Kushal Jaligama
# Runner Technique for Linked Lists

class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

def main():
  head = Node("a0")

  n = head

  for i in range(1, 5):
    n.next = Node("a" + str(i))
    n = n.next

  for i in range(0, 5):
    n.next = Node("b" + str(i))
    n = n.next

  n = head

  while n is not None:
    print(n.data)
    n = n.next

  # Runner technique, rearrange the elements of the LL so that
  # a's and b's are alternating

  p1 = head
  p2 = head

  while p1.next.next:
    p1 = p1.next.next
    p2 = p2.next


  # separate the linked lists

  p2 = p2.next
  p1.next = None
  p1 = head

# p2 will be at the midpoint and p1 will be at the end

  print("p1" + str(p1.data))
  print("p2" + str(p2.data))

  """
  h
  p1             p2
  a0 a1 a2 a3 a4 b0 b1 b2 b3 b4

  a0 b0 a1 b1 a2 b2 a3 a3 

  """

  while p1.next is not None and p2.next is not None:
    p1next = p1.next
    p2next = p2.next
    
    p1.next = p2
    p2.next = p1next
    
    p1 = p1next
    p2 = p2next


  print("runner")

  n = head

  while n is not None:
    print(n.data)
    n = n.next



if __name__ == '__main__':
  main()