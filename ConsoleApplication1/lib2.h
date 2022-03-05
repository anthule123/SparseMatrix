#pragma once

Vecto nhanSpaMatrix(SpaMatrix& A, Vecto& EM)
{
    vector<double> ans = vector<double>(A.size, 0);
    Vecto res;
    res.build(ans);
    for (int i = 0; i < A.size; i++) {
        ans[i] = 0;
        for (int j = 0; j < A.row[i].size(); j++) {
            int index = A.row[i][j].first;
            double v = A.row[i][j].second;
            ans[i] += v * EM.core[index];
        }
    }
    res.build(ans);
    return res;
};
Vecto sum(Vecto& A, Vecto& B) {
    Vecto ans;
    vector<double> c;
    for (int i = 0; i < A.size; i++) {
        c.push_back(A.core[i] + B.core[i]);
    }
    ans.build(c);
    return ans;
}
Vecto subtract(Vecto A, Vecto B) {
    Vecto ans;
    vector<double> c;
    for (int i = 0; i < A.size; i++) {
        c.push_back(A.core[i] - B.core[i]);
    }
    ans.build(c);
    return ans;
}
Vecto mulScala(double x, Vecto A) {
    Vecto ans = A;
    for (int i = 0; i < A.size; i++) {
        ans.core[i] = ans.core[i] * x;
    }
    return ans;
}
double dot(Vecto A, Vecto B) {
    double ans = 0;
    for (int i = 0; i < A.size; i++) {
        ans += A.core[i] * B.core[i];
    }
    return ans;
}