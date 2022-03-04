#pragma once

Vecto nhanSpaMatrix(SpaMatrix& A, Vecto& EM)
{
    vector<double> ans = vector<double>(A.n, 0);
    Vecto res;
    res.build(ans);
    for (int i = 0; i < A.n; i++) {
        ans[i] = 0;
        for (int j = 0; j < A.row[i].size(); j++) {
            int index = A.row[i][j].first;
            double v = A.row[i][j].second;
            ans[i] += v * EM.b[index];
        }
    }
    res.build(ans);
    return res;
};
Vecto sum(Vecto& A, Vecto & B) {
    Vecto ans;
    vector<double> c;
    for (int i = 0; i < A.n; i++) {
        c.push_back(A.b[i] + B.b[i]);
    }
    ans.build(c);
    return ans;
}