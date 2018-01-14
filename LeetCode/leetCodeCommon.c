//
//  leetCodeCommon.c
//  LeetCode
//
//  Created by lidaojian on 2018/1/11.
//  Copyright © 2018年 lidaojian. All rights reserved.
//

#include "leetCodeCommon.h"
#include <stdlib.h>

struct ListNode *tailCreatList(int a[], int n) {
    struct ListNode *head = NULL, *tail = NULL, *p = NULL;
    for (int i = 0; i < n; i ++) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = a[i];
        p->next = NULL;
        if (head == NULL) {
            head = p;
            tail = head;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    
    return head;
}

void printList(struct ListNode *p) {
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}