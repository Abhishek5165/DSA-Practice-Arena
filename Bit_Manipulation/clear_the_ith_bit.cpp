class Solution
{
  public:
    int replaceBit (int n, int k){
    int num = (n&(~(1<<k)));
    return num;
    }
};


// for toggling the ith bit use (n^(1<<k));