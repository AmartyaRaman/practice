
class Solution {
public:
    using ll = long long;

    const ll MOD = 1e9 + 7;
    const ll BASE = 911382323;

    vector<ll> h, p;

    void buildHash(vector<int>& nums) {
        int n = nums.size();

        h.assign(n + 1, 0);
        p.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            ll x = ((ll)nums[i] % MOD + MOD) % MOD;

            h[i + 1] = (h[i] * BASE + x) % MOD;
            p[i + 1] = (p[i] * BASE) % MOD;
        }
    }

    ll getHash(int l, int r) {
        int len = r - l;

        return (h[r] - h[l] * p[len] % MOD + MOD) % MOD;
    }

    bool isPossible(int len, int n) {
        unordered_map<ll, int> freq;

        for (int l = 0; l + len <= n; l++) {
            ll key = getHash(l, l + len);
            freq[key]++;
        }

        for (auto it : freq) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        buildHash(nums);

        int l = 1, r = n;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(mid, n)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
