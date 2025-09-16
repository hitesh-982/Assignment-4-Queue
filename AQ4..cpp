#include <iostream>
using namespace std;

class Q {
    char* a;
    int f, r, cap, sz;
public:
    Q(int c) {
        cap = c;
        a = new char[cap];
        f = 0; r = -1; sz = 0;
    }
    ~Q() { delete[] a; }
    bool empty() { return sz == 0; }
    void push(char v) {
        if (sz == cap) return;
        r = (r + 1) % cap;
        a[r] = v;
        sz++;
    }
    void pop() {
        if (empty()) return;
        f = (f + 1) % cap;
        sz--;
    }
    char front() {
        if (empty()) return '\0';
        return a[f];
    }
    void remove(char c) {
        if (empty()) return;
        int n = sz;
        for (int i = 0; i < n; i++) {
            char x = front();
            pop();
            if (x != c) push(x);
        }
    }
};

void solve(char* s, int n) {
    int f[26] = {0};
    Q q(n);
    cout << "out: ";
    for (int i = 0; i < n; i++) {
        char c = s[i];
        f[c - 'a']++;
        if (f[c - 'a'] == 1) q.push(c);
        else q.remove(c);
        while (!q.empty() && f[q.front() - 'a'] > 1) q.pop();
        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "n: ";
    cin >> n;
    char* s = new char[n];
    cout << "chars: ";
    for (int i = 0; i < n; i++) cin >> s[i];
    solve(s, n);
    delete[] s;
}
