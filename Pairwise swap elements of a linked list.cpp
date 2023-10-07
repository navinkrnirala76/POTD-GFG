Node* ptr1 = head;
        Node* ptr2 = head->next;
        
        Node* prev = NULL;
        
        while(ptr1 && ptr2)
        {
            
                Node* temp = ptr2->next;
                ptr2->next = ptr1;
                
                if(prev==NULL)
                    head = ptr2 ;
                else
                    prev->next = ptr2;
                    
                ptr1->next = temp;
                
                prev = ptr1;
                ptr1 = ptr1->next;
                if(ptr1)
                    ptr2 = ptr1->next;
            
        }
        return head;
