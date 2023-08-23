void read_xsect_rip_all_w(){

gStyle->SetTitleSize(0.11,"t"); 
string file_names_m12[11];
string file_names_m23[11];
string file_names_th[11];
string file_names_alph[11];

Float_t integral;
Float_t arr_m12_val[11][10];
Float_t arr_m12_xsect[11][10];
Float_t arr_m12_err[11][10];

Float_t arr_m23_val[11][10];
Float_t arr_m23_xsect[11][10];
Float_t arr_m23_err[11][10];

Float_t arr_th_val[11][10];
Float_t arr_th_xsect[11][10];
Float_t arr_th_err[11][10];

Float_t arr_alph_val[11][5];
Float_t arr_alph_xsect[11][5];
Float_t arr_alph_err[11][5];


Float_t arr_m12_val_1dim[10];
Float_t arr_m12_xsect_1dim[10];
Float_t arr_m12_err_1dim[10];

Float_t arr_m23_val_1dim[10];
Float_t arr_m23_xsect_1dim[10];
Float_t arr_m23_err_1dim[10];

Float_t arr_th_val_1dim[10];
Float_t arr_th_xsect_1dim[10];
Float_t arr_th_err_1dim[10];

Float_t arr_alph_val_1dim[5];
Float_t arr_alph_xsect_1dim[5];
Float_t arr_alph_err_1dim[5];




file_names_m12[0] ="data_w_gt_18/x130_184_xsec1d_mpippim_v2.dat"; 
file_names_m23[0] = "data_w_gt_18/x130_184_xsec1d_mpippr_v2.dat";
file_names_th[0] = "data_w_gt_18/x130_184_xsec1d_theta_pim_v2.dat";
file_names_alph[0] ="data_w_gt_18/x130_184_xsec1d_psi_pim_v2.dat";


file_names_m12[1] ="data_w_gt_18/x130_186_xsec1d_mpippim_v2.dat"; 
file_names_m23[1] = "data_w_gt_18/x130_186_xsec1d_mpippr_v2.dat";
file_names_th[1] = "data_w_gt_18/x130_186_xsec1d_theta_pim_v2.dat";
file_names_alph[1] ="data_w_gt_18/x130_186_xsec1d_psi_pim_v2.dat";



file_names_m12[2] ="data_w_gt_18/x130_189_xsec1d_mpippim_v2.dat"; 
file_names_m23[2] = "data_w_gt_18/x130_189_xsec1d_mpippr_v2.dat";
file_names_th[2] = "data_w_gt_18/x130_189_xsec1d_theta_pim_v2.dat";
file_names_alph[2] ="data_w_gt_18/x130_189_xsec1d_psi_pim_v2.dat";


file_names_m12[3] ="data_w_gt_18/x130_191_xsec1d_mpippim_v2.dat"; 
file_names_m23[3] = "data_w_gt_18/x130_191_xsec1d_mpippr_v2.dat";
file_names_th[3] = "data_w_gt_18/x130_191_xsec1d_theta_pim_v2.dat";
file_names_alph[3] ="data_w_gt_18/x130_191_xsec1d_psi_pim_v2.dat";


file_names_m12[4] ="data_w_gt_18/x130_194_xsec1d_mpippim_v2.dat"; 
file_names_m23[4] = "data_w_gt_18/x130_194_xsec1d_mpippr_v2.dat";
file_names_th[4] = "data_w_gt_18/x130_194_xsec1d_theta_pim_v2.dat";
file_names_alph[4] ="data_w_gt_18/x130_194_xsec1d_psi_pim_v2.dat";


file_names_m12[5] ="data_w_gt_18/x130_196_xsec1d_mpippim_v2.dat"; 
file_names_m23[5] = "data_w_gt_18/x130_196_xsec1d_mpippr_v2.dat";
file_names_th[5] = "data_w_gt_18/x130_196_xsec1d_theta_pim_v2.dat";
file_names_alph[5] ="data_w_gt_18/x130_196_xsec1d_psi_pim_v2.dat";


file_names_m12[6] ="data_w_gt_18/x130_199_xsec1d_mpippim_v2.dat"; 
file_names_m23[6] = "data_w_gt_18/x130_199_xsec1d_mpippr_v2.dat";
file_names_th[6] = "data_w_gt_18/x130_199_xsec1d_theta_pim_v2.dat";
file_names_alph[6] ="data_w_gt_18/x130_199_xsec1d_psi_pim_v2.dat";


file_names_m12[7] ="data_w_gt_18/x130_201_xsec1d_mpippim_v2.dat"; 
file_names_m23[7] = "data_w_gt_18/x130_201_xsec1d_mpippr_v2.dat";
file_names_th[7] = "data_w_gt_18/x130_201_xsec1d_theta_pim_v2.dat";
file_names_alph[7] ="data_w_gt_18/x130_201_xsec1d_psi_pim_v2.dat";



file_names_m12[8] ="data_w_gt_18/x130_204_xsec1d_mpippim_v2.dat"; 
file_names_m23[8] = "data_w_gt_18/x130_204_xsec1d_mpippr_v2.dat";
file_names_th[8] = "data_w_gt_18/x130_204_xsec1d_theta_pim_v2.dat";
file_names_alph[8] ="data_w_gt_18/x130_204_xsec1d_psi_pim_v2.dat";

file_names_m12[9] ="data_w_gt_18/x130_206_xsec1d_mpippim_v2.dat"; 
file_names_m23[9] = "data_w_gt_18/x130_206_xsec1d_mpippr_v2.dat";
file_names_th[9] = "data_w_gt_18/x130_206_xsec1d_theta_pim_v2.dat";
file_names_alph[9] ="data_w_gt_18/x130_206_xsec1d_psi_pim_v2.dat";


file_names_m12[10] ="data_w_gt_18/x130_209_xsec1d_mpippim_v2.dat"; 
file_names_m23[10] = "data_w_gt_18/x130_209_xsec1d_mpippr_v2.dat";
file_names_th[10] = "data_w_gt_18/x130_209_xsec1d_theta_pim_v2.dat";
file_names_alph[10] ="data_w_gt_18/x130_209_xsec1d_psi_pim_v2.dat";




 for (Short_t j=0; j<=10; j++){

string dummy,dummy_2,dummy_3;
 string number, number1;
string file=file_names_m12[j];
ifstream input(file.c_str());
if(input.is_open()){

//-------m12-------------------------


 for (Short_t i=1; i<=10; i++){

getline(input,number1);

number = number1.substr(2,number1.length());

dummy = number.substr(0,number.find(" "));
arr_m12_val[j][i-1] = atof(dummy.c_str());


dummy_2 = number.substr(dummy.length()+2,number.rfind(" "));
dummy_2 = dummy_2.substr(0,dummy_2.find(" "));
arr_m12_xsect[j][i-1] =  atof(dummy_2.c_str());


dummy_3 = number.substr(dummy.length()+dummy_2.length()+4,number.rfind(" "));
dummy_3 =dummy_3.substr(0,dummy_3.find(" "));
arr_m12_err[j][i-1] = atof(dummy_3.c_str());



cout << "m12   "<<arr_m12_val[j][i-1] << "   "<<arr_m12_xsect[j][i-1]<<" "<<arr_m12_err[j][i-1]<< "\n";

};
};
input.close();


//----------------m23---------------------

string file=file_names_m23[j];
ifstream input(file.c_str());
if(input.is_open()){
 for (Short_t i=1; i<=10; i++){

getline(input,number1);
number = number1.substr(2,number1.length());
dummy = number.substr(0,number.find(" "));
arr_m23_val[j][i-1] = atof(dummy.c_str());


dummy_2 = number.substr(dummy.length()+2,number.rfind(" "));
dummy_2 = dummy_2.substr(0,dummy_2.find(" "));
arr_m23_xsect[j][i-1] =  atof(dummy_2.c_str());


dummy_3 = number.substr(dummy.length()+dummy_2.length()+4,number.rfind(" "));
dummy_3 =dummy_3.substr(0,dummy_3.find(" "));
arr_m23_err[j][i-1] = atof(dummy_3.c_str());

cout <<"m23   "<<arr_m23_val[j][i-1] << "   "<<arr_m23_xsect[j][i-1]<<" "<<arr_m23_err[j][i-1]<< "\n";


};
};
input.close();

//------theta------------------

string file=file_names_th[j];
ifstream input(file.c_str());
if(input.is_open()){
 for (Short_t i=1; i<=10; i++){

getline(input,number1);
number = number1.substr(2,number1.length());
dummy = number.substr(0,number.find(" "));
arr_th_val[j][i-1] = atof(dummy.c_str());


dummy_2 = number.substr(dummy.length()+2,number.rfind(" "));
dummy_2 = dummy_2.substr(0,dummy_2.find(" "));
arr_th_xsect[j][i-1] =  atof(dummy_2.c_str());


dummy_3 = number.substr(dummy.length()+dummy_2.length()+4,number.rfind(" "));
dummy_3 =dummy_3.substr(0,dummy_3.find(" "));
arr_th_err[j][i-1] = atof(dummy_3.c_str());

arr_th_val[j][i-1] =arr_th_val[j][i-1]*3.1415/180.;

cout <<"th   "<<arr_th_val[j][i-1] << "   "<<arr_th_xsect[j][i-1]<<" "<<arr_th_err[j][i-1]<< "\n";
};
};
input.close();


//----------------alpha-----------------

string file=file_names_alph[j];
ifstream input(file.c_str());
if(input.is_open()){
 for (Short_t i=1; i<=5; i++){

getline(input,number1);
number = number1.substr(2,number1.length());
dummy = number.substr(0,number.find(" "));
arr_alph_val[j][i-1] = atof(dummy.c_str());


dummy_2 = number.substr(dummy.length()+2,number.rfind(" "));
dummy_2 = dummy_2.substr(0,dummy_2.find(" "));
arr_alph_xsect[j][i-1] =  atof(dummy_2.c_str());


dummy_3 = number.substr(dummy.length()+dummy_2.length()+4,number.rfind(" "));
dummy_3 =dummy_3.substr(0,dummy_3.find(" "));
arr_alph_err[j][i-1] = atof(dummy_3.c_str());

arr_alph_val[j][i-1] =arr_alph_val[j][i-1]*3.1415/180.;

cout <<"alp  "<<arr_alph_val[j][i-1] << "   "<<arr_alph_xsect[j][i-1]<<" "<<arr_alph_err[j][i-1]<< "\n";
};
};
input.close();

};

TH1F *h_m12[10];
TH1F *h_m23[10];
TH1F *h_th[10];
TH1F *h_alph[10];
Float_t W[10];
ostringstream qqq;

//Float_t W[11];
//TFile *MyFile2 = new TFile("out_27Aug_eps.root","READ");
//TFile *MyFile2 = new TFile("out_16Sept_eps.root","READ");
//TFile *MyFile2 = new TFile("out_18Aug_181_214_1dim_distr_ok_bigstat.root","READ");
//TFile *MyFile2 = new TFile("out_21Sept.root","READ");
//TFile *MyFile2 = new TFile("out_7_Oct_test.root","READ");

//TFile *MyFile2 = new TFile("out_13_Oct_test_gleb_130.root","READ");
//TFile *MyFile2 = new TFile("out_5Nov.root","READ");
//TFile *MyFile2 = new TFile("out_19Nov_130_18_21_4.root","READ");
//TFile *MyFile2 = new TFile("out_11Nov_test.root","READ");
TFile *MyFile2 = new TFile("out_20Nov_130_1dim.root","READ");

MyFile2->cd();

for (Short_t j=0; j<=9; j++){
W[j] = 1.8375+0.025*j;
qqq << "h_odn_inv_m12_" << 10000*(1.8375+0.025*j);
cout << qqq.str().c_str() <<"\n";
gDirectory->GetObject(qqq.str().c_str(),h_m12[j]);
qqq.str("");

qqq << "h_odn_inv_m23_" << 10000*(1.8375+0.025*j);
cout << qqq.str().c_str() <<"\n";
gDirectory->GetObject(qqq.str().c_str(),h_m23[j]);
qqq.str("");

qqq << "h_odn_theta_2_" << 10000*(1.8375+0.025*j);
cout << qqq.str().c_str() <<"\n";
gDirectory->GetObject(qqq.str().c_str(),h_th[j]);
qqq.str("");

qqq << "h_odn_alpha_" << 10000*(1.8375+0.025*j);
cout << qqq.str().c_str() <<"\n";
gDirectory->GetObject(qqq.str().c_str(),h_alph[j]);
qqq.str("");

};





//j=10;


TGraph *gr[10];

 
TCanvas *c1 = new TCanvas ("c1","c1",0,0,1200,800);
c1->Divide(5,2);

TCanvas *c2 = new TCanvas ("c2","c2",0,0,1200,800);
c2->Divide(5,2);

TCanvas *c3 = new TCanvas ("c3","c3",0,0,1200,800);
c3->Divide(5,2);


TCanvas *c4 = new TCanvas ("c4","c4",0,0,1200,800);
c4->Divide(5,2);


Float_t factor;


//integral = 0.;

for (Short_t j=0; j<=9; j++){

for (Short_t i=0; i<=9; i++){
arr_m12_val_1dim[i] = arr_m12_val[j][i];
arr_m12_xsect_1dim[i] = arr_m12_xsect[j][i];
arr_m12_err_1dim[i] = arr_m12_err[j][i];

arr_m23_val_1dim[i] = arr_m23_val[j][i];
arr_m23_xsect_1dim[i] = arr_m23_xsect[j][i];
arr_m23_err_1dim[i] = arr_m23_err[j][i];

arr_th_val_1dim[i] = arr_th_val[j][i];
arr_th_xsect_1dim[i] = arr_th_xsect[j][i];
arr_th_err_1dim[i] = arr_th_err[j][i];

//integral = integral +arr_th_xsect_1dim[i]*2.*3.1415/14. ;

};


for (Short_t i=0; i<=4; i++){


arr_alph_val_1dim[i] = arr_alph_val[j][i];
arr_alph_xsect_1dim[i] = arr_alph_xsect[j][i];
arr_alph_err_1dim[i] = arr_alph_err[j][i];


};

gr[j] = new TGraphErrors(10,arr_m12_val_1dim ,arr_m12_xsect_1dim, 0, arr_m12_err_1dim);

c1->cd(j+1);
c1->cd(j+1)->SetBottomMargin(0.25);
c1->cd(j+1)->SetLeftMargin(0.2);
gr[j]->SetMarkerStyle(21);
gr[j]->SetMarkerSize(0.8);
gr[j]->SetMarkerColor(kBlue);
gr[j]->SetLineColor(kBlue);
gr[j]->SetMarkerSize(0.9);


qqq << "W = "<<W[j] << " GeV";

gr[j]->SetTitle(qqq.str().c_str());
qqq.str("");

gr[j]->GetYaxis()->SetTitle("d#sigma/dM, #mub/GeV");
gr[j]->GetXaxis()->SetTitle("m12, GeV");
gr[j]->GetXaxis()->SetNdivisions(7);
gr[j]->GetYaxis()->SetNdivisions(7);
gr[j]->GetXaxis()->SetLabelSize(0.08);

gr[j]->GetXaxis()->SetTitleSize(0.08);
//gr->GetYaxis()->SetTitle("F_{2}");
gr[j]->GetYaxis()->SetLabelSize(0.07);
gr[j]->GetYaxis()->SetTitleSize(0.08);
gr[j]->Draw("AP");

//factor = 1./3000000.*100.;
//factor = 1./500000000.*14.*100.;
factor = 1./10000000.*100*10.;
factor = factor/((W[j]-0.938)-(0.13957+0.13957)+0.04);
h_m12[j]->Scale(factor);
h_m12[j]->SetLineColor(kBlack);
h_m12[j]->SetLineWidth(2);
h_m12[j]->Draw("same");

//-----------------------------------

c2->cd(j+1);
c2->cd(j+1)->SetBottomMargin(0.25);
c2->cd(j+1)->SetLeftMargin(0.2);

TGraph *gr1 = new TGraphErrors(10,arr_m23_val_1dim ,arr_m23_xsect_1dim, 0, arr_m23_err_1dim);
gr1->SetMarkerStyle(21);
gr1->SetMarkerSize(0.8);
gr1->SetMarkerColor(kBlue);
gr1->SetLineColor(kBlue);
gr1->SetMarkerSize(0.9);

qqq << "W = "<<W[j] << " GeV";
gr1->SetTitle(qqq.str().c_str());
qqq.str("");

gr1->GetYaxis()->SetTitle("d#sigma/dM, #mub/GeV");
gr1->GetXaxis()->SetTitle("m23, GeV");
gr1->GetXaxis()->SetNdivisions(7);
gr1->GetYaxis()->SetNdivisions(7);
gr1->GetXaxis()->SetLabelSize(0.08);

gr1->GetXaxis()->SetTitleSize(0.08);
//gr->GetYaxis()->SetTitle("F_{2}");
gr1->GetYaxis()->SetLabelSize(0.07);
gr1->GetYaxis()->SetTitleSize(0.08);

gr1->Draw("AP");


h_m23[j]->Scale(factor);
h_m23[j]->SetLineColor(kBlack);
h_m23[j]->SetLineWidth(2);
h_m23[j]->Draw("same");

//-----------------------------
c3->cd(j+1);
c3->cd(j+1)->SetBottomMargin(0.25);
c3->cd(j+1)->SetLeftMargin(0.2);


TGraph *gr2 = new TGraphErrors(10,arr_th_val_1dim ,arr_th_xsect_1dim, 0, arr_th_err_1dim);
gr2->SetMarkerStyle(21);
gr2->SetMarkerSize(0.8);
gr2->SetMarkerColor(kBlue);
gr2->SetLineColor(kBlue);
gr2->SetMarkerSize(0.9);


qqq << "W = "<<W[j] << " GeV";
gr2->SetTitle(qqq.str().c_str());
qqq.str("");
gr2->GetYaxis()->SetTitle("d#sigma/d(-cos#theta), #mub/rad");
gr2->GetXaxis()->SetTitle("theta, rad");
gr2->GetXaxis()->SetNdivisions(7);
gr2->GetYaxis()->SetNdivisions(7);
gr2->GetXaxis()->SetLabelSize(0.08);

gr2->GetXaxis()->SetTitleSize(0.08);
//gr->GetYaxis()->SetTitle("F_{2}");
gr2->GetYaxis()->SetLabelSize(0.07);
gr2->GetYaxis()->SetTitleSize(0.08);
gr2->GetXaxis()->SetRangeUser(0.,3.125); 


//factor = 1./3000000.;
//factor = 1./500000000.*14.;
factor = 1./10000000.*10.;
h_th[j]->Scale(factor);
//gr2->SetMaximum(1.05*h_th[j]->GetMaximum());
gr2->Draw("AP");



h_th[j]->SetLineColor(kBlack);
h_th[j]->SetLineWidth(2);
//h_th[j]->SetMaximum(1.2*h_th[j]->GetMaximum());
h_th[j]->Draw("same");



//--------------------
c4->cd(j+1);
c4->cd(j+1)->SetBottomMargin(0.25);
c4->cd(j+1)->SetLeftMargin(0.22);

TGraph *gr3 = new TGraphErrors(5,arr_alph_val_1dim ,arr_alph_xsect_1dim, 0, arr_alph_err_1dim);

gr3->SetMarkerStyle(21);
gr3->SetMarkerSize(0.8);
gr3->SetMarkerColor(kBlue);
gr3->SetLineColor(kBlue);
gr3->SetMarkerSize(0.9);

qqq << "W = "<<W[j] << " GeV";
gr3->SetTitle(qqq.str().c_str());
qqq.str("");

gr3->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/rad");
gr3->GetXaxis()->SetTitle("alpha, rad");
gr3->GetXaxis()->SetNdivisions(7);
gr3->GetYaxis()->SetNdivisions(7);
gr3->GetXaxis()->SetLabelSize(0.08);

gr3->GetXaxis()->SetTitleSize(0.08);
//gr->GetYaxis()->SetTitle("F_{2}");
gr3->GetYaxis()->SetLabelSize(0.07);
gr3->GetYaxis()->SetTitleSize(0.08);
gr3->GetXaxis()->SetRangeUser(0.,2.*3.125); 


gr3->Draw("AP");
//factor = 1./3000000.*100.;
//factor = 1./500000000.*100*14..;
factor = 1./10000000.*100.*10.;
factor = factor/3.14/2.;
h_alph[j]->Scale(factor);
h_alph[j]->SetLineColor(kBlack);
h_alph[j]->SetLineWidth(2);
h_alph[j]->Draw("same");

gr2->GetYaxis()->SetRangeUser(0.,1.8*h_th[j]->GetMaximum()); 
gr3->GetYaxis()->SetRangeUser(0.,4.5); 



};

 

};
