// 이산 푸리에 변환 알고르즘

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

#define PI 3.1415926535897932384626

using namespace std;

/*
vector<complex<double> > dft(vector<complex<double> > dataOri) {
	int N = dataOri.size();	
	vector<complex<double> > F;
	
	for (int k = 0; k < N; k++) {
		complex<double> tmp(0.0, 0.0);
		for (int x = 0; x < N; x++) {
			tmp += dataOri[x] * exp(complex<double>(0.0, -2*PI*k*x/N));
		}	
		F.push_back(tmp / complex<double> (N, 0));
	}
	return F;
}

vector<complex<double> > idft(vector<complex<double> > dataOri) {
	int N = dataOri.size();
	vector<complex<double> > f;

	for (int x = 0; x < N; x++) {
		complex<double> tmp = 0;
		for (int k = 0; k < N; k++) {
			tmp += dataOri[k] * exp(complex<double>(0.0, 2 * PI * k * x / N));
		}
		f.push_back(tmp);
	}
	return f;
}
*/

int main() {

	vector<complex<double> > ori{2,4,6,4,2,4,6,4,2,4,6,4,2,4,6,4};
	vector<complex<double> >  res, resres;
	res = dft(ori);
	resres = idft(res);
	

	for (int i = 0; i < res.size(); i++) {
		cout << sqrt(pow(res[i].real(), 2) + pow(res[i].imag(), 2)) << ' ';
	}
	cout << '\n';
	 
	for (int i = 0; i < res.size(); i++) {
		cout << resres[i].real() << ' ';
	}

	return 0;
}
