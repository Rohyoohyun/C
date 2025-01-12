#include <stdio.h>//201p(단어입력) + 203(탐색)
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data[100];
	struct Node* next;
}Node;

Node* insertFirst(Node* head, char* data){
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = head; // 새 노드가 기존 헤드를 가리키게
	return node;
}

Node* insert(Node* head, Node* pre, char* data){
	if(pre == NULL) return head;
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = pre->next; // 새 노드 다음을 pre로 설정
	pre->next = node; // pre의 다음을 새 노드로 지정
	return head;
}
Node* deleteFirst(Node* head){
 	if(head == NULL) return NULL;
	Node* temp = head; // 현재 헤드 임시저장
	head = head->next; // 헤드를 다음 노드로 지정
	free(temp);
	return head;
}
Node* delete(Node* head, Node* pre){
	//프리가 가리키는 다음 노드를 삭제
	if(pre == NULL || pre->next == NULL) return head;
	Node* temp = pre->next;
	pre->next = temp->next;
	free(temp);
	return head;
}
void printList(Node* head){
	while(head!=NULL){ // 리스트 순회...?
		printf("%s->", head->data); 
		head = head->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL;
	Node* p;
  char str[3][10] ={"melon","kiwi","apple"};
	char find[10];
	
	head = insertFirst(head,str[0]); //melon 입력
	printList(head);
	
	head = insertFirst(head,str[1]);
	printList(head);
	
	head = insertFirst(head,str[2]);
	printList(head);
	
	printf("찾을 데이터를 입력하세요\n");
	scanf("%s",find);
	for(p=head; p!=NULL; p=p->next){
		//printf("%s",p->data);
		if(strcmp(p->data,find) == 0)
			printf("%s을 찾았습니다.",find);
	}
	return 0;
}


