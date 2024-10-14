// Time Complexity : O(1);
// Space Complexity : O(1);

// Approch - 1 Using Extra Variable...

class Solution{   
public:
    pair<int, int> get(int a, int b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;

    return {a,b};
    }
};

// Approch - 2 Using +/- Operator ..
// Without using extra variable ..

class Solution{   
public:
    pair<int, int> get(int a, int b){
 
    a = a+b;
    b = a-b;
    a = a-b;

    return {a,b};
    }
};

// Approch - 3 Using XOR Operator ..
// Without using extra variable ..

class Solution{   
public:
    pair<int, int> get(int a, int b){
 
    a = a^b;
    b = a^b;
    a = a^b;

    return {a,b};
    }
};