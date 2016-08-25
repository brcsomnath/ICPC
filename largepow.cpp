const int md = 1000000007;
 
inline int mul(int a, int b) {
  return (long long)a * b % md;
}
 
int pw(int a, int b) {
  int x = 1;
  while (b > 0) {
    if (b & 1) {
      x = mul(x, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
