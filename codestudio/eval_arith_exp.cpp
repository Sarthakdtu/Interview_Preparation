//https://www.codingninjas.com/codestudio/problems/arithmetic-expression-evaluation_1170517
#include<bits/stdc++.h>
using namespace std;
string sol(int a, int b, char op){
   // cout<<"Solving "<<b<<op<<a<<endl;
    int s = 0;
    if(op == '+')
        s = b + a;
    else if(op =='-')
        s = b - a;
    else if(op == '/')
        s = b/a;
    else
        s = b*a;
    return to_string(s);
}

string parse_num(string &exp, int &i){
    string num = "";
    for(;i<exp.size();i++){
        if(exp[i]>='0' && exp[i]<='9')
            num += to_string(exp[i]);
        else
            break;
    }
    return num;
}

bool perced(char a, char b){
    if(b == '/' || b=='*')
        return false;
    return true;
}

void evaluater(stack<string> &stk, stack<char> &sop){
    if(sop.empty())
        return ;
    if(sop.top() == '('){
        sop.pop();
        if(sop.empty())
            sop.push('(');
        return ;
    }

    int a = stoi(stk.top());
    stk.pop();
    char op = sop.top();
    sop.pop();
    int b = stoi(stk.top());
    stk.pop();

    if(sop.empty())
        sop.push('(');
    else if(sop.top() == '('){
        sop.pop();
        if(sop.empty())
            sop.push('(');
    }
    stk.push(sol(b, a, op));
}



int evaluateArithmeticExpression(string &exp) {
    int i=0;
    bool res = true;
    stack<string> stk;
    stack<char> sop;
    int n = exp.size();
    while(i<n){
        if(exp[i] == ')'){
            evaluater(stk, sop);
            i++;
        }
        else{
            char ch = exp[i];
            if(ch =='+' || ch=='-' || ch=='*' || ch=='/'){
                while(!sop.empty() && !preced(ch, sop.top())){
                   evaluater(stk, sop);
                }
                sop.push(ch); 
                i++;
            }
            else if(ch == '('){
                sop.push(ch);
                i++;
            }
            else{
                stk.push(parse_num(exp, i));
            }
        }
    }
    return stk.top();

}