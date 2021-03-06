#include<bits/stdc++.h>
using namespace std;

int phi(long long c) {
  long long ret = c;
  for (int i = 2; i * i <= c; ++i)
    if (c % i == 0) {
      ret -= ret / i;
      while (c % i == 0)
        c /= i;
    }
  if (c > 1)
    ret -= ret / c;
  return ret;
}

long long pow_mod(long long a, long long b, long long c) {
  long long ret = 1;
  while (b) {
    if (b & 1)
      ret = (ret * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return ret;
}

int main() {
  string b, n;
  long long c;
  cin >> b >> n >> c;
  long long bb = 0, nn = 0;
  for (int i = 0; i < b.length(); ++i)
    bb = (bb * 10 + b[i] - '0') % c;
  bool flag = false;
  long long m = phi(c);
  for (int i = 0; i < n.length(); ++i) {
    nn = nn * 10 + n[i] - '0';
    if (nn > m) {
      flag = true;
      nn %= m;
    }
  }
  if (flag)
    nn += m;
  --nn;
  long long ans = (((bb + c - 1) % c) * pow_mod(bb, nn, c)) % c;
  if (ans == 0)
    ans = c;
  cout << ans << endl;
  return 0;
}
