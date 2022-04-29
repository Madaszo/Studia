from ssl import HAS_TLSv1_1


class Node:
    def __init__(self):
        self.val = None
        self.next = None
class Container:
    def __init__(self,h1,h2):
        self.h1=h1
        self.h2=h2


def scalanie(p1,p2):
    if (p1.val < p2.val):
        s = p1
        p1 = p1.next
        s.next = None
    else:
        s = p2
        p2 = p2.next
        s.next = None
    sp = s
    while(p1 != None):
        if(p2 == None):
            sp.next = p1
            break
        if(p1.val < p2.val):
            sp.next = p1
            p1 = p1.next 
            sp = sp.next
        else:
            sp.next = p2
            p2 = p2.next
            sp = sp.next
    sp.next = p2
    p2 = None
    while(sp.next != None):
        sp = sp.next
    return s, sp

def podziel(p):
    new = p
    while(p != None):
        if (p.next.val < p.val):
            tmp = p
            p = p.next
            tmp.next = None 
            return new
        p = p.next


def mergesort(p):
    head = p
    while(1):
        n=0
        tail = head
        while(p.next != None):
            s1 = podziel(p)
            n+=1
            if p.next == None:
                tail.next = s1
            else:
                s2 = podziel(p)
                n+=1
                m_head , m_tail = scalanie(s1,s2)
                tail.next = m_head
                tail = m_tail
        p = head 