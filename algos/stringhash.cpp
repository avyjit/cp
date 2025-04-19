template <long long P, long long M>
class StringHash {
    vector<long long> H, inv;

    long long powm(long long x, long long p) {
        if (p == 0) return 1;
    
        long long y = powm(x, p/2);
        y *= y; y %= M;
    
        if (p % 2) {
            y *= x;
            y %= M;
        }
    
        return y;
    }

public:
    StringHash(const string &s) {
        long long n = s.size();
        H.resize(n);
        inv.resize(n);

        inv[0] = 1; long long pinv = powm(P, M-2);
        for (long long i = 1; i < n; ++i) inv[i] = (pinv*inv[i-1]) % M;
    
        long long ppow = 1; H[0] = (s[0] - 'a' + 1);
    
        for (long long i = 1; i < n; ++i) {
            ppow = ppow * P % M;
            H[i] = (H[i-1] + (ppow * (s[i] - 'a' + 1) % M)) % M;
        }
    }

    long long query(long long l, long long r) {
        long long hash = H[r] % M;
        if (l > 0) hash = (M + hash - H[l-1]) % M;
        hash = (hash * inv[l]) % M;
        return hash;
    }

    long long query() {
        return H.back();
    }
};