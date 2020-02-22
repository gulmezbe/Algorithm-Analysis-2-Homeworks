/*
* Student name: Behlül Gülmez
* Student ID : 150140113
* Date: 18/03/2018
*/

#include <ctime>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class node{
	public:
		int farmer;
		int fox;
		int rabbit;
		int carrot;
		vector <node*>frontnodes;
		node* backnode;
		node& operator=(const node&);
		node();
		~node();
};

class graph{
	public:
		int visitednodenumber;
		int maxkeptnumber;
		node* start;
		stack <node*>laststack;
		queue <node*>myqueue;
		stack <node*>mystack;
		vector <string>visited;
		vector <string>rejected;
		bool isvisited(string);
		bool isrejected(string);
		void bfs();
		void dfs();
		void finalprint(double);
		graph();
		~graph();
		
};

node::node(){
	farmer = 0;
	fox = 0;
	rabbit = 0;
	carrot = 0;
	backnode = NULL;
}

node::~node(){
	
}

graph::graph(){
	visitednodenumber = 0;
	maxkeptnumber = 0;
	visited.push_back("0000");
	rejected.push_back("0110");rejected.push_back("0011");rejected.push_back("0111");rejected.push_back("1000");rejected.push_back("1100");rejected.push_back("1001");
}

graph::~graph(){
	
}

node& node::operator=(const node& z){
	farmer = z.farmer;
	fox = z.fox;
	rabbit = z.rabbit;
	carrot = z.carrot;
}

bool graph::isvisited(string coming_string){
	for(int i = 0 ; i < visited.size() ; i++){
		if(coming_string == visited[i])
			return true;
	}
	return false;
}

bool graph::isrejected(string coming_string){
	for(int i = 0 ; i < rejected.size() ; i++){
		if(coming_string == rejected[i])
			return true;
	}
	return false;
}

void graph::bfs(){
	bool found = false;
	node* temp;
	start = new node;
	myqueue.push(start);
	while(!myqueue.empty()){	
		temp = myqueue.front();
		myqueue.pop();
		visitednodenumber++;
		if(temp->farmer == 1 && temp->fox == 1 && temp->rabbit == 1 && temp->carrot == 1){
			found = true;
			break;
		}
		if(temp->farmer == 0){
			if(temp->fox == 0 && temp->rabbit == 0 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1000") && !isrejected("1000")){
					visited.push_back("1000");
					myqueue.push(temp1);
				}					
					
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->fox = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1100") && !isrejected("1100")){
					visited.push_back("1100");
					myqueue.push(temp2);
				}
					
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->rabbit = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1010") && !isrejected("1010")){
					visited.push_back("1010");
					myqueue.push(temp3);
				}	
					
				node* temp4;				
				temp4 = new node;
				temp4->farmer = temp->farmer;
				temp4->fox = temp->fox;
				temp4->rabbit = temp->rabbit;
				temp4->carrot = temp->carrot;
				temp4->farmer = 1;
				temp4->carrot = 1;
				temp4->backnode = temp;
				temp->frontnodes.push_back(temp4);
				if(!isvisited("1001") && !isrejected("1001")){
					visited.push_back("1001");
					myqueue.push(temp4);
				}															
			}
			else if(temp->fox == 1 && temp->rabbit == 0 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1100") && !isrejected("1100")){
					visited.push_back("1100");
					myqueue.push(temp1);
				}	
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->rabbit = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1110") && !isrejected("1110")){
					visited.push_back("1110");
					myqueue.push(temp2);
				}	
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->carrot = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1101") && !isrejected("1101")){
					visited.push_back("1101");
					myqueue.push(temp3);
				}	
			}
			else if(temp->fox == 0 && temp->rabbit == 1 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1010") && !isrejected("1010")){
					visited.push_back("1010");
					myqueue.push(temp1);
				}	
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->fox = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1110") && !isrejected("1110")){
					visited.push_back("1110");
					myqueue.push(temp2);
				}	
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->carrot = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1011") && !isrejected("1011")){
					visited.push_back("1011");
					myqueue.push(temp3);
				}	
			}
			else if(temp->fox == 0 && temp->rabbit == 0 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1001") && !isrejected("1001")){
					visited.push_back("1001");
					myqueue.push(temp1);
				}	
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->fox = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1101") && !isrejected("1101")){
					visited.push_back("1101");
					myqueue.push(temp2);
				}	
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->rabbit = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1011") && !isrejected("1011")){
					visited.push_back("1011");
					myqueue.push(temp3);
				}	
			}
			else if(temp->fox == 1 && temp->rabbit == 0 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1101") && !isrejected("1101")){
					visited.push_back("1101");
					myqueue.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->rabbit = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1111") && !isrejected("1111")){
					visited.push_back("1111");
					myqueue.push(temp2);
				}
			}
		}
		else{
			if(temp->fox == 0 && temp->rabbit == 1 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0010") && !isrejected("0010")){
					visited.push_back("0010");
					myqueue.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->rabbit = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0000") && !isrejected("0000")){
					visited.push_back("0000");
					myqueue.push(temp2);
				}
			}
			else if(temp->fox == 1 && temp->rabbit == 0 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0101") && !isrejected("0101")){
					visited.push_back("0101");
					myqueue.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->fox = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0001") && !isrejected("0001")){
					visited.push_back("0001");
					myqueue.push(temp2);
				}
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 0;
				temp3->carrot = 0;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("0100") && !isrejected("0100")){
					visited.push_back("0100");
					myqueue.push(temp3);
				}
			}
			else if(temp->fox == 0 && temp->rabbit == 1 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0011") && !isrejected("0011")){
					visited.push_back("0011");
					myqueue.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->rabbit = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0001") && !isrejected("0001")){
					visited.push_back("0001");
					myqueue.push(temp2);
				}
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 0;
				temp3->carrot = 0;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("0010") && !isrejected("0010")){
					visited.push_back("0010");
					myqueue.push(temp3);
				}
			}
			else if(temp->fox == 1 && temp->rabbit == 1 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0110") && !isrejected("0110")){
					visited.push_back("0110");
					myqueue.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->rabbit = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0100") && !isrejected("0100")){
					visited.push_back("0100");
					myqueue.push(temp2);
				}
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 0;
				temp3->fox = 0;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("0010") && !isrejected("0010")){
					visited.push_back("0010");
					myqueue.push(temp3);
				}
			}
		}
	}
	while(temp->backnode != NULL){
		laststack.push(temp);
		maxkeptnumber++;
		temp = temp->backnode;
	}
	laststack.push(temp);
	maxkeptnumber++;
}

void graph::dfs(){
	bool found = false;
	node* temp;
	start = new node;
	mystack.push(start);
	while(!mystack.empty()){
		temp = mystack.top();
		mystack.pop();
		visitednodenumber++;
		if(temp->farmer == 1 && temp->fox == 1 && temp->rabbit == 1 && temp->carrot == 1){
			found = true;
			break;
		}
		if(temp->farmer == 0){
			if(temp->fox == 0 && temp->rabbit == 0 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1000") && !isrejected("1000")){
					visited.push_back("1000");
					mystack.push(temp1);
				}					
					
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->fox = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1100") && !isrejected("1100")){
					visited.push_back("1100");
					mystack.push(temp2);
				}
					
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->rabbit = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1010") && !isrejected("1010")){
					visited.push_back("1010");
					mystack.push(temp3);
				}	
					
				node* temp4;				
				temp4 = new node;
				temp4->farmer = temp->farmer;
				temp4->fox = temp->fox;
				temp4->rabbit = temp->rabbit;
				temp4->carrot = temp->carrot;
				temp4->farmer = 1;
				temp4->carrot = 1;
				temp4->backnode = temp;
				temp->frontnodes.push_back(temp4);
				if(!isvisited("1001") && !isrejected("1001")){
					visited.push_back("1001");
					mystack.push(temp4);
				}															
			}
			else if(temp->fox == 1 && temp->rabbit == 0 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1100") && !isrejected("1100")){
					visited.push_back("1100");
					mystack.push(temp1);
				}	
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->rabbit = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1110") && !isrejected("1110")){
					visited.push_back("1110");
					mystack.push(temp2);
				}	
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->carrot = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1101") && !isrejected("1101")){
					visited.push_back("1101");
					mystack.push(temp3);
				}	
			}
			else if(temp->fox == 0 && temp->rabbit == 1 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1010") && !isrejected("1010")){
					visited.push_back("1010");
					mystack.push(temp1);
				}	
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->fox = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1110") && !isrejected("1110")){
					visited.push_back("1110");
					mystack.push(temp2);
				}	
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->carrot = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1011") && !isrejected("1011")){
					visited.push_back("1011");
					mystack.push(temp3);
				}	
			}
			else if(temp->fox == 0 && temp->rabbit == 0 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1001") && !isrejected("1001")){
					visited.push_back("1001");
					mystack.push(temp1);
				}	
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->fox = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1101") && !isrejected("1101")){
					visited.push_back("1101");
					mystack.push(temp2);
				}	
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 1;
				temp3->rabbit = 1;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("1011") && !isrejected("1011")){
					visited.push_back("1011");
					mystack.push(temp3);
				}	
			}
			else if(temp->fox == 1 && temp->rabbit == 0 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 1;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("1101") && !isrejected("1101")){
					visited.push_back("1101");
					mystack.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 1;
				temp2->rabbit = 1;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("1111") && !isrejected("1111")){
					visited.push_back("1111");
					mystack.push(temp2);
				}
			}
		}
		else{
			if(temp->fox == 0 && temp->rabbit == 1 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0010") && !isrejected("0010")){
					visited.push_back("0010");
					mystack.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->rabbit = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0000") && !isrejected("0000")){
					visited.push_back("0000");
					mystack.push(temp2);
				}
			}
			else if(temp->fox == 1 && temp->rabbit == 0 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0101") && !isrejected("0101")){
					visited.push_back("0101");
					mystack.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->fox = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0001") && !isrejected("0001")){
					visited.push_back("0001");
					mystack.push(temp2);
				}
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 0;
				temp3->carrot = 0;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("0100") && !isrejected("0100")){
					visited.push_back("0100");
					mystack.push(temp3);
				}
			}
			else if(temp->fox == 0 && temp->rabbit == 1 && temp->carrot == 1){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0011") && !isrejected("0011")){
					visited.push_back("0011");
					mystack.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->rabbit = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0001") && !isrejected("0001")){
					visited.push_back("0001");
					mystack.push(temp2);
				}
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 0;
				temp3->carrot = 0;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("0010") && !isrejected("0010")){
					visited.push_back("0010");
					mystack.push(temp3);
				}
			}
			else if(temp->fox == 1 && temp->rabbit == 1 && temp->carrot == 0){
				node* temp1;				
				temp1 = new node;
				temp1->farmer = temp->farmer;
				temp1->fox = temp->fox;
				temp1->rabbit = temp->rabbit;
				temp1->carrot = temp->carrot;
				temp1->farmer = 0;
				temp1->backnode = temp;
				temp->frontnodes.push_back(temp1);
				if(!isvisited("0110") && !isrejected("0110")){
					visited.push_back("0110");
					mystack.push(temp1);
				}
				
				node* temp2;				
				temp2 = new node;
				temp2->farmer = temp->farmer;
				temp2->fox = temp->fox;
				temp2->rabbit = temp->rabbit;
				temp2->carrot = temp->carrot;
				temp2->farmer = 0;
				temp2->rabbit = 0;
				temp2->backnode = temp;
				temp->frontnodes.push_back(temp2);
				if(!isvisited("0100") && !isrejected("0100")){
					visited.push_back("0100");
					mystack.push(temp2);
				}
				
				node* temp3;				
				temp3 = new node;
				temp3->farmer = temp->farmer;
				temp3->fox = temp->fox;
				temp3->rabbit = temp->rabbit;
				temp3->carrot = temp->carrot;
				temp3->farmer = 0;
				temp3->fox = 0;
				temp3->backnode = temp;
				temp->frontnodes.push_back(temp3);
				if(!isvisited("0010") && !isrejected("0010")){
					visited.push_back("0010");
					mystack.push(temp3);
				}
			}
		}
	}
	while(temp->backnode != NULL){
		laststack.push(temp);
		maxkeptnumber++;
		temp = temp->backnode;
	}
	laststack.push(temp);
	maxkeptnumber++;
}

void graph::finalprint(double x){
	cout << "Number of the visited nodes: " << visitednodenumber << endl << "Maximum number of nodes kept in the memory: " << maxkeptnumber << endl << "Running time: " << x / CLOCKS_PER_SEC << " seconds"<< endl << "Solution move count: " << laststack.size() << endl;
	while(1){
		node* temp;
		temp = laststack.top();
		if(temp->farmer == 0)
			cout << "Farmer ";
		if(temp->rabbit == 0)
			cout << "Rabbit ";
		if(temp->carrot == 0)
			cout << "Carrot ";
		if(temp->fox == 0)
			cout << "Fox ";
		cout << "|| ";
		if(temp->farmer == 1)
			cout << "Farmer ";
		if(temp->rabbit == 1)
			cout << "Rabbit ";
		if(temp->carrot == 1)
			cout << "Carrot ";
		if(temp->fox == 1)
			cout << "Fox ";
		
		laststack.pop();
		if(laststack.empty())
			break;
		
		cout << endl << "(Farmer, ";
		if(temp->rabbit != laststack.top()->rabbit)
			cout << "Rabbit, ";
		if(temp->carrot != laststack.top()->carrot)
			cout << "Carrot, ";
		if(temp->fox != laststack.top()->fox)
			cout << "Fox, ";
			
		if(temp->farmer > laststack.top()->farmer)
			cout << "< )" << endl;
		else
			cout << "> )" << endl;
	}
}


int main(int argc, char *argv[]){
	clock_t begin = clock();
	double total;
	graph mygraph;

	if(strcmp("bfs",argv[1]) == 0){
		cout << "Algorithm: BFS" << endl;
		mygraph.bfs();
	}		
	else if(strcmp("dfs",argv[1]) == 0){
		cout << "Algorithm: DFS" << endl;
		mygraph.dfs();
	}		
	else
		cout << "Wrong parameters" << endl;

	clock_t end = clock();
	total = end - begin;
	
	mygraph.finalprint(total);

	return 0;
}
