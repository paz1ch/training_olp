#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000;
const int MAXA = 10000;

int n, q;
vector<int> a(MAXN + 1);
vector<vector<int>> blocks;
int blockSize;

void buildBlocks() {
    blocks.clear();
    blockSize = sqrt(n);
    blocks.resize((n + blockSize - 1) / blockSize);
    for (int i = 0; i < n; ++i) {
        blocks[i / blockSize].push_back(a[i + 1]);
    }
    for (auto &block : blocks) {
        sort(block.begin(), block.end());
    }
}

void update(int idx, int value) {
    int blockIdx = (idx - 1) / blockSize;
    auto &block = blocks[blockIdx];
    auto it = lower_bound(block.begin(), block.end(), a[idx]);
    block.erase(it);
    a[idx] = value;
    block.insert(lower_bound(block.begin(), block.end(), value), value);
}

int query(int l, int r, int k) {
    int count = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        int blockL = i * blockSize + 1;
        int blockR = min(n, (i + 1) * blockSize);
        if (blockR < l || blockL > r) continue;
        if (blockL >= l && blockR <= r) {
            // Khối nằm hoàn toàn trong [l, r]
            count += blocks[i].end() - upper_bound(blocks[i].begin(), blocks[i].end(), k);
        } else {
            // Khối bị cắt bởi biên
            for (int j = max(l, blockL); j <= min(r, blockR); ++j) {
                if (a[j] > k) count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    buildBlocks();

    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int i, v;
            cin >> i >> v;
            update(i, v);
        } else if (type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(l, r, k) << '\n';
        }
    }

    return 0;
}
