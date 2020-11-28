#include <bits/stdc++.h> 
using namespace std; 

	long long int a=10080;
	long long int b=1100;
	long long int c=a+b;
	long long int d=b+c;

int precedence(char op)
{ 
    if(op == '+'||op == '-') 
    return 1; 
    if(op == '*'||op == '/') 
    return 2; 
    return 0; 
} 
	
int operation(long long int a,long long int b, char op)
{ 
    switch(op)
	{ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
    } 
    return 0;
} 
int mod(string num, int caca) 
{ 
    int res = 0; 
  
    for (int i = 0; i < num.length(); i++)
    {
        res = (res*10 + (int)num[i] - '0') %caca; 	
	}  
    return res; 
} 

int evaluate(string tokens)
{ 
    stack <long long int> val;
    stack <char> ops;
    for (int i=0;i<tokens.length();i++)
    {
    	//cout << i  << " ";
    	if(tokens[i] == ' ') 
	    continue;
	    else if(tokens[i] == '(')
		{ 
	        ops.push(tokens[i]); 
	    } 
	    else if(tokens[i]=='A')
		{
			val.push(a); 
	    } 
	    else if(tokens[i]=='B')
		{
			val.push(b); 
	    } 
	    else if(tokens[i]=='C')
		{
			val.push(c); 
	    } 
	    else if(tokens[i]=='D')
		{
			val.push(d); 
	    } 
	    else if(tokens[i] == ')') 
	    { 
	        while(!ops.empty() && ops.top() != '(') 
	        { 
	            long long int num1 = val.top(); 
	            val.pop(); 
	              
	            long long int num2 = val.top(); 
	            val.pop(); 
	              
	            char op = ops.top(); 
	            ops.pop(); 
	              
	            val.push(operation(num1, num2, op)); 
	        } 
	        if(!ops.empty()) 
	        ops.pop(); 
	    } 
	    else
        { 
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
			{ 
				//cout<< i << " ";
                long long int num1 = val.top(); 
                //cout << "a";
	            val.pop(); 
	              
	            long long int num2 = val.top(); 
	            //cout << "b";
	            val.pop(); 
	              
	            char op = ops.top(); 
	            //cout << "c";
	            ops.pop(); 
	              
	            val.push(operation(num1, num2, op)); 
	            //cout << "d";
            } 
            ops.push(tokens[i]); 
        } 
    } 
    while(!ops.empty())
	{ 
        long long int num1 = val.top(); 
	    val.pop(); 
	              
	    long long int num2 = val.top(); 
        val.pop(); 
          
        char op = ops.top(); 
        ops.pop(); 
          
        val.push(operation(num1, num2, op)); 
    } 
    return val.top(); 
} 


int main ()
{
	int t;
	cin >> t;
	for (int tc=0;tc<t;tc++)
	{
		int n;
		string ops;
		cin >> n;
		getchar();
		getline (cin,ops);
		//cout<<endl<<ops<<endl;
		long long int boi = evaluate(ops);
		//cout << boi;
		string real = to_string (boi);
		string bebop;
		for (int i=0;i<n;i++)
		{
			bebop+=real;
		}
		int ans =  mod(bebop,3331);
		cout << ans << endl; 
	}
}
