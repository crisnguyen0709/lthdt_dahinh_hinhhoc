#include<bits/stdc++.h>
using namespace std;
class hinh{
	public:
		virtual double dientich()=0;
		virtual double chuvi()=0;
		virtual void nhap()=0;
		virtual void xuat()=0;
};

class hinhtron:public hinh{
	private:
		double r;
		const double PI = 3.141592653589793;
	public:
		double dientich() override;
		double chuvi() override;
		void nhap() override;
		void xuat() override;
};

void hinhtron::nhap(){
	cout<<"Ban kinh:";
	cin>>r;
	cin.ignore();
}

double hinhtron::chuvi(){
	return 2*PI*r;
}

double hinhtron::dientich(){
	return PI*r*r;
}

void hinhtron::xuat(){
	cout<<"Hinh tron:"<<endl;
	cout<<"Chu vi:"<<fixed<<setprecision(3)<<chuvi()<<endl;
	cout<<"Dien tich:"<<fixed<<setprecision(2)<<dientich()<<endl;
}

class hcn:public hinh{
	private:
		int dai;
		int rong;
	public:
		double dientich() override;
		double chuvi() override;
		void nhap() override;
		void xuat() override;
};

void hcn::nhap(){
	cout<<"Chieu dai:";
	cin>>dai;
	cin.ignore();
	cout<<"Chieu rong:";
	cin>>rong;
	cin.ignore();
}

double hcn::chuvi(){
	return 2*(dai+rong);
}

double hcn::dientich(){
	return dai*rong;
}

void hcn::xuat(){
	cout<<"Hinh chu nhat:"<<endl;
	cout<<"Chu vi:"<<chuvi()<<endl;
	cout<<"Dien tich:"<<dientich()<<endl;
}

class tamgiac:public hinh{
	private:
		int a,b,c;
	public:
		double dientich() override;
		double chuvi() override;
		void nhap() override;
		void xuat() override;
};

void tamgiac::nhap(){
	cout<<"a:";
	cin>>a;
	cin.ignore();
	cout<<"b:";
	cin>>b;
	cin.ignore();
	cout<<"c:";
	cin>>c;
	cin.ignore();
}

double tamgiac::chuvi(){
	return (a+b+c);
}

double tamgiac::dientich(){
	double p=chuvi()/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

void tamgiac::xuat(){
	cout<<"Hinh tam giac:"<<endl;
	cout<<"Chu vi:"<<fixed<<setprecision(2)<<chuvi()<<endl;
	cout<<"Dien tich:"<<fixed<<setprecision(2)<<dientich()<<endl;
}
int main(){
	int n;
	cin>>n;
	cin.ignore();
	vector<hinh*> ds;
	for(int i=0;i<n;i++){
		string loai;
		cout<<"Loai:";
		getline(cin,loai);
		if(loai=="hinh tron"){
			ds.push_back(new hinhtron);
		}
		else if(loai=="hinh chu nhat"){
			ds.push_back(new hcn);
		}
		else if(loai=="hinh tam giac"){
			ds.push_back(new tamgiac);
		}
		
		ds[i]->nhap();
	}

	for(int i=0;i<n;i++){
		ds[i]->xuat();
	}
	cout<<endl;
	
	
	double tong=0;
	for(int i=0;i<n;i++){
		tong+=ds[i]->chuvi();
	}
	cout<<"Tong chu vi:"<<fixed<<setprecision(2)<<tong<<endl;
	
	double tong_dt=0;
	for(int i=0;i<n;i++){
		tong_dt+=ds[i]->dientich();
	}
	cout<<"Tong dien tich:"<<fixed<<setprecision(2)<<tong_dt<<endl;
	
	double maxdt=0;
	for(int i=0;i<n;i++){
		if(ds[i]->dientich() > maxdt){
			maxdt=ds[i]->dientich();		}
	}
	
	for(int i=0;i<n;i++){
		if(maxdt==ds[i]->dientich()){
			cout<<"Hinh co dien tich lon nhat la:"<<endl;
			ds[i]->xuat();
		}
	}
}