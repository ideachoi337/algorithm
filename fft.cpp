#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

const double PI = acos(-1);

void FFT(vector<complex<double> > &f, complex<double> W) {
	int N = f.size();

	if (N == 1) return;

	vector<complex<double> > even(N>>1), odd(N>>1);
	for (int i = 0; i < N; i++) {
		if (i & 1) odd[i>>1] = f[i];
		else even[i>>1] = f[i];
	}

	FFT(even, W*W);
	FFT(odd, W*W);

	complex<double> z(1, 0);
	for (int i = 0; i < N/2; i++) {
		f[i] = even[i] + z*odd[i];
		f[i+ N/2] = even[i] - z*odd[i];

		z *= W;
	}


}

vector<int> multiply(vector<int> v, vector<int> u) {
	vector<int> w(v.size() + u.size() - 1);

	int n = 1;
	while(n <= v.size() || n <= u.size()) n *= 2;
	n*=2;

	v.resize(n);
	u.resize(n);

	vector<complex<double> > _v(n), _u(n);
	for (int i = 0; i < n; i++) {
		_v[i] = complex<double>(v[i], 0);
		_u[i] = complex<double>(u[i], 0);
	}	

	complex<double> W (cos(2*PI/n), sin(2*PI/n));

	FFT(_v, W);
	FFT(_u, W);

	vector<complex<double> > _w(n);
	for (int i = 0; i < n; i++) {
		_w[i] = _v[i] * _u[i];
	}

	FFT(_w, complex<double>(1.0,0.0)/W);
	for (int i = 0; i < n; i++) {
		_w[i] /= complex<double> (n, 0);
		_w[i] = complex<double>(round(_w[i].real()), round(_w[i].imag()));
		w[i] = _w[i].real();
	}
	return w;
}

int main() {
	vector<int> v1{1, 2, 3, 4, 1, 2, 3, 4};
	vector<int> v2{5, 8, 7, 6};
	vector<int> w = multiply(v1, v2);
	for (int i = 0; i < w.size(); i++) {
		cout << w[i] << ' ';
	}
	return 0;
}
