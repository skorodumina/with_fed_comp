//This script compares invariant mass distributions for the two cross section sets: quasi-free cross sections off protons in the deuteron (Skorodumina) and free proton cross sections (Fedotov). The script plots the two cross section sets and then plots their ratios.

void fed_comp_inv(){
ostringstream qqq;
gStyle->SetOptStat(0);
gStyle->SetTitleSize(0.07,"t"); 

TCanvas *c_arr[11];
TCanvas *c1_arr[11];

TCanvas *c2 = new TCanvas("c2","c2",0,0,1000,1000);
c2->Divide(4,4);


Short_t i,j,k,Q2bin_index, Nb;

Short_t nbins[12] = {21, 21, 20, 20, 19, 18, 17, 16, 14, 13, 12, 10};

Short_t theta_bins[21] = {7, 7, 9, 9, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11};

string dummy,dummy_2,dummy_3;
string number, number1;

Float_t arr_thet_val[11][21][11];
Float_t arr_thet_xsect[11][21][11];
Float_t arr_thet_err[11][21][11];

//k - Q2 bins
//j - W bins
//i - theta bins

Float_t fedQ2bin, fedWbin;

//Q2bin_index = 1;
//fedQ2bin = 0.425+0.05*Q2bin_index;

string file_names_thet[11][21];


TH1F *h_mass1[21];
TH1F *h_mass2[20];
TH1F *h_mass3[20];
TH1F *h_mass4[19];
TH1F *h_mass5[18];
TH1F *h_mass6[17];
TH1F *h_mass7[16];
TH1F *h_mass8[14];
TH1F *h_mass9[13];
TH1F *h_mass10[12];
TH1F *h_mass11[10];


TH1D *inv_mass1[21];
TH1D *inv_mass2[20];
TH1D *inv_mass3[20];
TH1D *inv_mass4[19];
TH1D *inv_mass5[18];
TH1D *inv_mass6[17];
TH1D *inv_mass7[16];
TH1D *inv_mass8[14];
TH1D *inv_mass9[13];
TH1D *inv_mass10[12];
TH1D *inv_mass11[10];

TH1F *h_fract1[21];
TH1F *h_fract2[20];
TH1F *h_fract3[20];
TH1F *h_fract4[19];
TH1F *h_fract5[18];
TH1F *h_fract6[17];
TH1F *h_fract7[16];
TH1F *h_fract8[14];
TH1F *h_fract9[13];
TH1F *h_fract10[12];
TH1F *h_fract11[10];

//Fedotov's data
for (Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

fedQ2bin = 0.425+0.05*Q2bin_index;
k = Q2bin_index - 1;

for (j=0;j<nbins[Q2bin_index];j++){

fedWbin = 1.3125+j*0.025;

//xsec1d_mpippr.dat
//xsec1d_mpippim.dat
//xsec1d_mpimpr.dat


qqq.str("");
if (!(k==10)) qqq << "two_pi_exp_data/Fedotov_data_Q2_0425_0975/Q2_0"<<1000.*fedQ2bin-25.<<"_0"<<1000.*fedQ2bin+25.<<"/w_"<<1000.*fedWbin-12.5<<"_"<<1000.*fedWbin+12.5<<"/xsec1d_mpimpr.dat";

if (k==10) qqq << "two_pi_exp_data/Fedotov_data_Q2_0425_0975/Q2_0"<<1000.*fedQ2bin-25.<<"_"<<1000.*fedQ2bin+25.<<"/w_"<<1000.*fedWbin-12.5<<"_"<<1000.*fedWbin+12.5<<"/xsec1d_mpimpr.dat";

file_names_thet[k][j] =qqq.str().c_str();

cout <<"k = "<< k << " "<< file_names_thet[k][j] <<endl;
};
};

//----------------inv m-----------------

for (Q2bin_index = 1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;
for (j=0;j<nbins[Q2bin_index];j++){
cout <<"k = "<< k << " "<< file_names_thet[k][j] <<endl;

string file=file_names_thet[k][j];
ifstream input(file.c_str());

if(input.is_open()){
for (i=1; i<=theta_bins[j]; i++){

getline(input,number1);
number = number1.substr(0,number1.length());
dummy = number.substr(0,number.find(" "));
arr_thet_val[k][j][i-1] = atof(dummy.c_str());

dummy_2 = number.substr(dummy.length()+1,number.rfind(" "));
dummy_2 = dummy_2.substr(0,dummy_2.find(" "));
arr_thet_xsect[k][j][i-1] =  atof(dummy_2.c_str());

dummy_3 = number.substr(dummy.length()+dummy_2.length()+2,number.rfind(" "));
dummy_3 =dummy_3.substr(0,dummy_3.find(" "));
arr_thet_err[k][j][i-1] = atof(dummy_3.c_str());

cout <<"k = "<<k<<", j = "<<j<<", i = "<<i<<" "<<arr_thet_val[k][j][i-1] << "   "<<arr_thet_xsect[k][j][i-1]<<" "<<arr_thet_err[k][j][i-1]<< "\n";
};
};
input.close();
};
};

//m_pip_p "/h1prj_inv_m_pip_p_1_bin_corr";
//m_pip_pim "/h2prj_inv_m_pip_pim_1_bin_corr";
//m_pim_p "/h3prj_inv_m_pim_p_1_bin_corr";

//Skorodumina's data
TFile *MyFile1 = new TFile("out_fin_2021.root","READ");
MyFile1->cd();

for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

fedQ2bin = 0.425+0.05*Q2bin_index;
k = Q2bin_index - 1;

for (Short_t j=0; j<nbins[Q2bin_index]; j++){
qqq.str("");
qqq << "q2_" << fedQ2bin << "/w_" << 1.3125+0.025*j << "/h3prj_inv_m_pim_p_1_bin_corr";
//cout <<qqq.str().c_str()<<" rr\n";
if (k==0) gDirectory->GetObject(qqq.str().c_str(),inv_mass1[j]);
if (k==1) gDirectory->GetObject(qqq.str().c_str(),inv_mass2[j]);
if (k==2) gDirectory->GetObject(qqq.str().c_str(),inv_mass3[j]);
if (k==3) gDirectory->GetObject(qqq.str().c_str(),inv_mass4[j]);
if (k==4) gDirectory->GetObject(qqq.str().c_str(),inv_mass5[j]);
if (k==5) gDirectory->GetObject(qqq.str().c_str(),inv_mass6[j]);
if (k==6) gDirectory->GetObject(qqq.str().c_str(),inv_mass7[j]);
if (k==7) gDirectory->GetObject(qqq.str().c_str(),inv_mass8[j]);
if (k==8) gDirectory->GetObject(qqq.str().c_str(),inv_mass9[j]);
if (k==9) gDirectory->GetObject(qqq.str().c_str(),inv_mass10[j]);
if (k==10) gDirectory->GetObject(qqq.str().c_str(),inv_mass11[j]);

qqq.str("");
};

};



for (Q2bin_index = 1;Q2bin_index<=11;Q2bin_index++){
k = Q2bin_index - 1;
for (Short_t j=0; j<nbins[Q2bin_index]; j++){

 qqq.str("");
if (k==0) qqq << "h_inv_mass1_" << j;
if (k==0) h_mass1[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass1[j]->GetBinLowEdge(1),inv_mass1[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass1[j]->GetBinWidth(1));

if (k==1) qqq << "h_inv_mass2_" << j;
if (k==1) h_mass2[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass2[j]->GetBinLowEdge(1),inv_mass2[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass2[j]->GetBinWidth(1));

if (k==2) qqq << "h_inv_mass3_" << j;
if (k==2) h_mass3[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass3[j]->GetBinLowEdge(1),inv_mass3[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass3[j]->GetBinWidth(1));

if (k==3) qqq << "h_inv_mass4_" << j;
if (k==3) h_mass4[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass4[j]->GetBinLowEdge(1),inv_mass4[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass4[j]->GetBinWidth(1) );

if (k==4) qqq << "h_inv_mass5_" << j;
if (k==4) h_mass5[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass5[j]->GetBinLowEdge(1),inv_mass5[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass5[j]->GetBinWidth(1) );

if (k==5) qqq << "h_inv_mass6_" << j;
if (k==5) h_mass6[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass6[j]->GetBinLowEdge(1),inv_mass6[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass6[j]->GetBinWidth(1) );

if (k==6) qqq << "h_inv_mass7_" << j;
if (k==6) h_mass7[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass7[j]->GetBinLowEdge(1),inv_mass7[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass7[j]->GetBinWidth(1) );

if (k==7) qqq << "h_inv_mass8_" << j;
if (k==7) h_mass8[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass8[j]->GetBinLowEdge(1),inv_mass8[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass8[j]->GetBinWidth(1));

if (k==8) qqq << "h_inv_mass9_" << j;
if (k==8) h_mass9[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass9[j]->GetBinLowEdge(1),inv_mass9[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass9[j]->GetBinWidth(1));

if (k==9) qqq << "h_inv_mass10_" << j;
if (k==9) h_mass10[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass10[j]->GetBinLowEdge(1),inv_mass10[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass10[j]->GetBinWidth(1));

if (k==10) qqq << "h_inv_mass11_" << j;
if (k==10) h_mass11[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[j]+1,inv_mass11[j]->GetBinLowEdge(1),inv_mass11[j]->GetBinLowEdge(theta_bins[j])+2*inv_mass11[j]->GetBinWidth(1));

 qqq.str("");
};
};


for (Q2bin_index = 1;Q2bin_index<=11;Q2bin_index++){
k = Q2bin_index - 1;
for (Short_t j=0; j<nbins[Q2bin_index]; j++){

if (k==0)  h_mass1[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==0)  h_mass1[j]->SetBinError(0.,theta_bins[j]+1);

if (k==1)  h_mass2[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==1)  h_mass2[j]->SetBinError(0.,theta_bins[j]+1);

if (k==2)  h_mass3[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==2)  h_mass3[j]->SetBinError(0.,theta_bins[j]+1);

if (k==3)  h_mass4[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==3)  h_mass4[j]->SetBinError(0.,theta_bins[j]+1);

if (k==4)  h_mass5[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==4)  h_mass5[j]->SetBinError(0.,theta_bins[j]+1);

if (k==5)  h_mass6[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==5)  h_mass6[j]->SetBinError(0.,theta_bins[j]+1);

if (k==6)  h_mass7[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==6)  h_mass7[j]->SetBinError(0.,theta_bins[j]+1);

if (k==7)  h_mass8[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==7)  h_mass8[j]->SetBinError(0.,theta_bins[j]+1);

if (k==8)  h_mass9[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==8)  h_mass9[j]->SetBinError(0.,theta_bins[j]+1);

if (k==9)  h_mass10[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==9)  h_mass10[j]->SetBinError(0.,theta_bins[j]+1);

if (k==10)  h_mass11[j]->SetBinContent(0.,theta_bins[j]+1);
if (k==10)  h_mass11[j]->SetBinError(0.,theta_bins[j]+1);

};
};





for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

qqq.str("");
qqq << "c_arr" << k;
c_arr[k] = new TCanvas (qqq.str().c_str(),qqq.str().c_str(),0,0,1000,1000);
c_arr[k]->Divide(5,4);

qqq.str("");
qqq << "c_ratio_arr" << k;
c1_arr[k] = new TCanvas (qqq.str().c_str(),qqq.str().c_str(),0,0,1000,1000);
c1_arr[k]->Divide(5,4);

};

for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){
k = Q2bin_index - 1;

for (Short_t j=0; j<nbins[Q2bin_index]; j++){

for (i=1; i<=theta_bins[j]; i++){

if (k==0)  h_mass1[j]->Fill(arr_thet_val[0][j][i-1], arr_thet_xsect[0][j][i-1]);
if (k==0)  h_mass1[j]->SetBinError(h_mass1[j]->FindBin(arr_thet_val[0][j][i-1]),arr_thet_err[0][j][i-1]);  
cout << Q2bin_index <<" "<< j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
if (k==1)   h_mass2[j]->Fill(arr_thet_val[1][j][i-1], arr_thet_xsect[1][j][i-1]);
if (k==1)   h_mass2[j]->SetBinError(h_mass2[j]->FindBin(arr_thet_val[1][j][i-1]),arr_thet_err[1][j][i-1]);  

if (k==2)   h_mass3[j]->Fill(arr_thet_val[2][j][i-1], arr_thet_xsect[2][j][i-1]);
if (k==2)   h_mass3[j]->SetBinError(h_mass3[j]->FindBin(arr_thet_val[2][j][i-1]),arr_thet_err[2][j][i-1]);  

if (k==3)   h_mass4[j]->Fill(arr_thet_val[3][j][i-1], arr_thet_xsect[3][j][i-1]);
if (k==3)   h_mass4[j]->SetBinError(h_mass4[j]->FindBin(arr_thet_val[3][j][i-1]),arr_thet_err[3][j][i-1]);  

if (k==4)   h_mass5[j]->Fill(arr_thet_val[4][j][i-1], arr_thet_xsect[4][j][i-1]);
if (k==4)   h_mass5[j]->SetBinError(h_mass5[j]->FindBin(arr_thet_val[4][j][i-1]),arr_thet_err[4][j][i-1]);  

if (k==5)   h_mass6[j]->Fill(arr_thet_val[5][j][i-1], arr_thet_xsect[5][j][i-1]);
if (k==5)   h_mass6[j]->SetBinError(h_mass6[j]->FindBin(arr_thet_val[5][j][i-1]),arr_thet_err[5][j][i-1]);  

if (k==6)   h_mass7[j]->Fill(arr_thet_val[6][j][i-1], arr_thet_xsect[6][j][i-1]);
if (k==6)   h_mass7[j]->SetBinError(h_mass7[j]->FindBin(arr_thet_val[6][j][i-1]),arr_thet_err[6][j][i-1]);  

if (k==7)   h_mass8[j]->Fill(arr_thet_val[7][j][i-1], arr_thet_xsect[7][j][i-1]);
if (k==7)   h_mass8[j]->SetBinError(h_mass8[j]->FindBin(arr_thet_val[7][j][i-1]),arr_thet_err[7][j][i-1]);  

if (k==8)   h_mass9[j]->Fill(arr_thet_val[8][j][i-1], arr_thet_xsect[8][j][i-1]);
if (k==8)   h_mass9[j]->SetBinError(h_mass9[j]->FindBin(arr_thet_val[8][j][i-1]),arr_thet_err[8][j][i-1]);  

if (k==9)   h_mass10[j]->Fill(arr_thet_val[9][j][i-1], arr_thet_xsect[9][j][i-1]);
if (k==9)   h_mass10[j]->SetBinError(h_mass10[j]->FindBin(arr_thet_val[9][j][i-1]),arr_thet_err[9][j][i-1]);  

if (k==10)   h_mass11[j]->Fill(arr_thet_val[10][j][i-1], arr_thet_xsect[10][j][i-1]);
if (k==10)   h_mass11[j]->SetBinError(h_mass11[j]->FindBin(arr_thet_val[10][j][i-1]),arr_thet_err[10][j][i-1]);

};

};
};



for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

cout << nbins[Q2bin_index] <<" bb\n";
for (Short_t j=0; j<nbins[Q2bin_index]; j++){


if (k==0){
c_arr[0]->cd(j+1);
c_arr[0]->cd(j+1)->SetBottomMargin(0.15);
c_arr[0]->cd(j+1)->SetLeftMargin(0.15);

h_mass1[j]->SetMarkerStyle(20);
h_mass1[j]->SetMarkerColor(kBlue);
h_mass1[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass1[j]->SetTitle(qqq.str().c_str());
h_mass1[j]->SetTitleSize(0.13);
h_mass1[j]->GetYaxis()->SetLabelSize(0.05);
h_mass1[j]->GetXaxis()->SetLabelSize(0.06);
h_mass1[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass1[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass1[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass1[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass1[j]->GetXaxis()->SetTitleSize(0.065);
h_mass1[j]->GetYaxis()->SetTitleSize(0.065);
h_mass1[j]->SetMinimum(0.25*h_mass1[j]->GetMinimum());
h_mass1[j]->SetMaximum(1.25*h_mass1[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass1[j]->Draw("e1pX0");

inv_mass1[j]->SetMarkerStyle(20);
inv_mass1[j]->SetMarkerColor(kBlack);
inv_mass1[j]->SetLineColor(kBlack);

inv_mass1[j]->Draw("pex0 e1 same");


h_fract1[j] = (TH1F*)inv_mass1[j]->Clone();
h_fract1[j]->Divide(h_mass1[j]);

c1_arr[0]->cd(j+1);
c1_arr[0]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[0]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract1[j]->SetTitle(qqq.str().c_str());
h_fract1[j]->SetTitleSize(0.13);
h_fract1[j]->GetYaxis()->SetTitle("ratio");
h_fract1[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract1[j]->Draw("pex0 e1");


};


if (k==1){
c_arr[1]->cd(j+1);
c_arr[1]->cd(j+1)->SetBottomMargin(0.15);
c_arr[1]->cd(j+1)->SetLeftMargin(0.15);

h_mass2[j]->SetMarkerStyle(20);
h_mass2[j]->SetMarkerColor(kBlue);
h_mass2[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass2[j]->SetTitle(qqq.str().c_str());
h_mass2[j]->SetTitleSize(0.13);
h_mass2[j]->GetYaxis()->SetLabelSize(0.05);
h_mass2[j]->GetXaxis()->SetLabelSize(0.06);
h_mass2[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass2[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass2[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass2[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass2[j]->GetXaxis()->SetTitleSize(0.065);
h_mass2[j]->GetYaxis()->SetTitleSize(0.065);
h_mass2[j]->SetMinimum(0.25*h_mass2[j]->GetMinimum());
h_mass2[j]->SetMaximum(1.25*h_mass2[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass2[j]->Draw("e1pX0");

inv_mass2[j]->SetMarkerStyle(20);
inv_mass2[j]->SetMarkerColor(kBlack);
inv_mass2[j]->SetLineColor(kBlack);

inv_mass2[j]->Draw("pex0 e1 same");

h_fract2[j] = (TH1F*)inv_mass2[j]->Clone();
h_fract2[j]->Divide(h_mass2[j]);

c1_arr[1]->cd(j+1);
c1_arr[1]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[1]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract2[j]->SetTitle(qqq.str().c_str());
h_fract2[j]->SetTitleSize(0.13);
h_fract2[j]->GetYaxis()->SetTitle("ratio");
h_fract2[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract2[j]->Draw("pex0 e1");
};


if (k==2){
c_arr[2]->cd(j+1);
c_arr[2]->cd(j+1)->SetBottomMargin(0.15);
c_arr[2]->cd(j+1)->SetLeftMargin(0.15);

h_mass3[j]->SetMarkerStyle(20);
h_mass3[j]->SetMarkerColor(kBlue);
h_mass3[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass3[j]->SetTitle(qqq.str().c_str());
h_mass3[j]->SetTitleSize(0.13);
h_mass3[j]->GetYaxis()->SetLabelSize(0.05);
h_mass3[j]->GetXaxis()->SetLabelSize(0.06);
h_mass3[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass3[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass3[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass3[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass3[j]->GetXaxis()->SetTitleSize(0.065);
h_mass3[j]->GetYaxis()->SetTitleSize(0.065);
h_mass3[j]->SetMinimum(0.25*h_mass3[j]->GetMinimum());
h_mass3[j]->SetMaximum(1.25*h_mass3[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass3[j]->Draw("e1pX0");

inv_mass3[j]->SetMarkerStyle(20);
inv_mass3[j]->SetMarkerColor(kBlack);
inv_mass3[j]->SetLineColor(kBlack);

inv_mass3[j]->Draw("pex0 e1 same");

h_fract3[j] = (TH1F*)inv_mass3[j]->Clone();
h_fract3[j]->Divide(h_mass3[j]);

c1_arr[2]->cd(j+1);
c1_arr[2]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[2]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract3[j]->SetTitle(qqq.str().c_str());
h_fract3[j]->SetTitleSize(0.13);
h_fract3[j]->GetYaxis()->SetTitle("ratio");
h_fract3[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract3[j]->Draw("pex0 e1");
};


if (k==3){
c_arr[3]->cd(j+1);
c_arr[3]->cd(j+1)->SetBottomMargin(0.15);
c_arr[3]->cd(j+1)->SetLeftMargin(0.15);

h_mass4[j]->SetMarkerStyle(20);
h_mass4[j]->SetMarkerColor(kBlue);
h_mass4[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass4[j]->SetTitle(qqq.str().c_str());
h_mass4[j]->SetTitleSize(0.13);
h_mass4[j]->GetYaxis()->SetLabelSize(0.05);
h_mass4[j]->GetXaxis()->SetLabelSize(0.06);
h_mass4[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass4[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass4[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass4[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass4[j]->GetXaxis()->SetTitleSize(0.065);
h_mass4[j]->GetYaxis()->SetTitleSize(0.065);
h_mass4[j]->SetMinimum(0.25*h_mass4[j]->GetMinimum());
h_mass4[j]->SetMaximum(1.25*h_mass4[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass4[j]->Draw("e1pX0");

inv_mass4[j]->SetMarkerStyle(20);
inv_mass4[j]->SetMarkerColor(kBlack);
inv_mass4[j]->SetLineColor(kBlack);

inv_mass4[j]->Draw("pex0 e1 same");


h_fract4[j] = (TH1F*)inv_mass4[j]->Clone();
h_fract4[j]->Divide(h_mass4[j]);

c1_arr[3]->cd(j+1);
c1_arr[3]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[3]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract4[j]->SetTitle(qqq.str().c_str());
h_fract4[j]->SetTitleSize(0.13);
h_fract4[j]->GetYaxis()->SetTitle("ratio");
h_fract4[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract4[j]->Draw("pex0 e1");
};

if (k==4){
c_arr[4]->cd(j+1);
c_arr[4]->cd(j+1)->SetBottomMargin(0.15);
c_arr[4]->cd(j+1)->SetLeftMargin(0.15);

h_mass5[j]->SetMarkerStyle(20);
h_mass5[j]->SetMarkerColor(kBlue);
h_mass5[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass5[j]->SetTitle(qqq.str().c_str());
h_mass5[j]->SetTitleSize(0.13);
h_mass5[j]->GetYaxis()->SetLabelSize(0.05);
h_mass5[j]->GetXaxis()->SetLabelSize(0.06);
h_mass5[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass5[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass5[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass5[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass5[j]->GetXaxis()->SetTitleSize(0.065);
h_mass5[j]->GetYaxis()->SetTitleSize(0.065);
h_mass5[j]->SetMinimum(0.25*h_mass5[j]->GetMinimum());
h_mass5[j]->SetMaximum(1.25*h_mass5[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass5[j]->Draw("e1pX0");

inv_mass5[j]->SetMarkerStyle(20);
inv_mass5[j]->SetMarkerColor(kBlack);
inv_mass5[j]->SetLineColor(kBlack);

inv_mass5[j]->Draw("pex0 e1 same");

h_fract5[j] = (TH1F*)inv_mass5[j]->Clone();
h_fract5[j]->Divide(h_mass5[j]);

c1_arr[4]->cd(j+1);
c1_arr[4]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[4]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract5[j]->SetTitle(qqq.str().c_str());
h_fract5[j]->SetTitleSize(0.13);
h_fract5[j]->GetYaxis()->SetTitle("ratio");
h_fract5[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract5[j]->Draw("pex0 e1");
};

if (k==5){
c_arr[5]->cd(j+1);
c_arr[5]->cd(j+1)->SetBottomMargin(0.15);
c_arr[5]->cd(j+1)->SetLeftMargin(0.15);

h_mass6[j]->SetMarkerStyle(20);
h_mass6[j]->SetMarkerColor(kBlue);
h_mass6[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass6[j]->SetTitle(qqq.str().c_str());
h_mass6[j]->SetTitleSize(0.13);
h_mass6[j]->GetYaxis()->SetLabelSize(0.05);
h_mass6[j]->GetXaxis()->SetLabelSize(0.06);
h_mass6[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass6[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass6[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass6[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass6[j]->GetXaxis()->SetTitleSize(0.065);
h_mass6[j]->GetYaxis()->SetTitleSize(0.065);
h_mass6[j]->SetMinimum(0.25*h_mass6[j]->GetMinimum());
h_mass6[j]->SetMaximum(1.25*h_mass6[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass6[j]->Draw("e1pX0");

inv_mass6[j]->SetMarkerStyle(20);
inv_mass6[j]->SetMarkerColor(kBlack);
inv_mass6[j]->SetLineColor(kBlack);

inv_mass6[j]->Draw("pex0 e1 same");

h_fract6[j] = (TH1F*)inv_mass6[j]->Clone();
h_fract6[j]->Divide(h_mass6[j]);

c1_arr[5]->cd(j+1);
c1_arr[5]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[5]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract6[j]->SetTitle(qqq.str().c_str());
h_fract6[j]->SetTitleSize(0.13);
h_fract6[j]->GetYaxis()->SetTitle("ratio");
h_fract6[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract6[j]->Draw("pex0 e1");
};


if (k==6){
c_arr[6]->cd(j+1);
c_arr[6]->cd(j+1)->SetBottomMargin(0.15);
c_arr[6]->cd(j+1)->SetLeftMargin(0.15);

h_mass7[j]->SetMarkerStyle(20);
h_mass7[j]->SetMarkerColor(kBlue);
h_mass7[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass7[j]->SetTitle(qqq.str().c_str());
h_mass7[j]->SetTitleSize(0.13);
h_mass7[j]->GetYaxis()->SetLabelSize(0.05);
h_mass7[j]->GetXaxis()->SetLabelSize(0.06);
h_mass7[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass7[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass7[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass7[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass7[j]->GetXaxis()->SetTitleSize(0.065);
h_mass7[j]->GetYaxis()->SetTitleSize(0.065);
h_mass7[j]->SetMinimum(0.25*h_mass7[j]->GetMinimum());
h_mass7[j]->SetMaximum(1.25*h_mass7[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass7[j]->Draw("e1pX0");

inv_mass7[j]->SetMarkerStyle(20);
inv_mass7[j]->SetMarkerColor(kBlack);
inv_mass7[j]->SetLineColor(kBlack);

inv_mass7[j]->Draw("pex0 e1 same");

h_fract7[j] = (TH1F*)inv_mass7[j]->Clone();
h_fract7[j]->Divide(h_mass7[j]);

c1_arr[6]->cd(j+1);
c1_arr[6]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[6]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract7[j]->SetTitle(qqq.str().c_str());
h_fract7[j]->SetTitleSize(0.13);
h_fract7[j]->GetYaxis()->SetTitle("ratio");
h_fract7[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract7[j]->Draw("pex0 e1");
};

if (k==7){
c_arr[7]->cd(j+1);
c_arr[7]->cd(j+1)->SetBottomMargin(0.15);
c_arr[7]->cd(j+1)->SetLeftMargin(0.15);

h_mass8[j]->SetMarkerStyle(20);
h_mass8[j]->SetMarkerColor(kBlue);
h_mass8[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "k7Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass8[j]->SetTitle(qqq.str().c_str());
h_mass8[j]->SetTitleSize(0.13);
h_mass8[j]->GetYaxis()->SetLabelSize(0.05);
h_mass8[j]->GetXaxis()->SetLabelSize(0.06);
h_mass8[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass8[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass8[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass8[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass8[j]->GetXaxis()->SetTitleSize(0.065);
h_mass8[j]->GetYaxis()->SetTitleSize(0.065);
h_mass8[j]->SetMinimum(0.25*h_mass8[j]->GetMinimum());
h_mass8[j]->SetMaximum(1.25*h_mass8[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass8[j]->Draw("e1pX0");

inv_mass8[j]->SetMarkerStyle(20);
inv_mass8[j]->SetMarkerColor(kBlack);
inv_mass8[j]->SetLineColor(kBlack);

inv_mass8[j]->Draw("pex0 e1 same");

h_fract8[j] = (TH1F*)inv_mass8[j]->Clone();
h_fract8[j]->Divide(h_mass8[j]);

c1_arr[7]->cd(j+1);
c1_arr[7]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[7]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "k7Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract8[j]->SetTitle(qqq.str().c_str());
h_fract8[j]->SetTitleSize(0.13);
h_fract8[j]->GetYaxis()->SetTitle("ratio");
h_fract8[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract8[j]->Draw("pex0 e1");
};

if (k==8){
c_arr[8]->cd(j+1);
c_arr[8]->cd(j+1)->SetBottomMargin(0.15);
c_arr[8]->cd(j+1)->SetLeftMargin(0.15);

h_mass9[j]->SetMarkerStyle(20);
h_mass9[j]->SetMarkerColor(kBlue);
h_mass9[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "k8Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass9[j]->SetTitle(qqq.str().c_str());
h_mass9[j]->SetTitleSize(0.13);
h_mass9[j]->GetYaxis()->SetLabelSize(0.05);
h_mass9[j]->GetXaxis()->SetLabelSize(0.06);
h_mass9[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass9[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass9[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass9[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass9[j]->GetXaxis()->SetTitleSize(0.065);
h_mass9[j]->GetYaxis()->SetTitleSize(0.065);
h_mass9[j]->SetMinimum(0.25*h_mass9[j]->GetMinimum());
h_mass9[j]->SetMaximum(1.25*h_mass9[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass9[j]->Draw("e1pX0");

inv_mass9[j]->SetMarkerStyle(20);
inv_mass9[j]->SetMarkerColor(kBlack);
inv_mass9[j]->SetLineColor(kBlack);

inv_mass9[j]->Draw("pex0 e1 same");

h_fract9[j] = (TH1F*)inv_mass9[j]->Clone();
h_fract9[j]->Divide(h_mass9[j]);

c1_arr[8]->cd(j+1);
c1_arr[8]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[8]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "k8Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract9[j]->SetTitle(qqq.str().c_str());
h_fract9[j]->SetTitleSize(0.13);
h_fract9[j]->GetYaxis()->SetTitle("ratio");
h_fract9[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract9[j]->Draw("pex0 e1");
};

if (k==9){
c_arr[9]->cd(j+1);
c_arr[9]->cd(j+1)->SetBottomMargin(0.15);
c_arr[9]->cd(j+1)->SetLeftMargin(0.15);

h_mass10[j]->SetMarkerStyle(20);
h_mass10[j]->SetMarkerColor(kBlue);
h_mass10[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "k9qQ2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass10[j]->SetTitle(qqq.str().c_str());
h_mass10[j]->SetTitleSize(0.13);
h_mass10[j]->GetYaxis()->SetLabelSize(0.05);
h_mass10[j]->GetXaxis()->SetLabelSize(0.06);
h_mass10[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass10[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass10[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass10[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass10[j]->GetXaxis()->SetTitleSize(0.065);
h_mass10[j]->GetYaxis()->SetTitleSize(0.065);
h_mass10[j]->SetMinimum(0.25*h_mass10[j]->GetMinimum());
h_mass10[j]->SetMaximum(1.25*h_mass10[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass10[j]->Draw("e1pX0");

inv_mass10[j]->SetMarkerStyle(20);
inv_mass10[j]->SetMarkerColor(kBlack);
inv_mass10[j]->SetLineColor(kBlack);

inv_mass10[j]->Draw("pex0 e1 same");

h_fract10[j] = (TH1F*)inv_mass10[j]->Clone();
h_fract10[j]->Divide(h_mass10[j]);

c1_arr[9]->cd(j+1);
c1_arr[9]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[9]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "k9Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract10[j]->SetTitle(qqq.str().c_str());
h_fract10[j]->SetTitleSize(0.13);
h_fract10[j]->GetYaxis()->SetTitle("ratio");
h_fract10[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract10[j]->Draw("pex0 e1");
};

if (k==10){
c_arr[10]->cd(j+1);
c_arr[10]->cd(j+1)->SetBottomMargin(0.15);
c_arr[10]->cd(j+1)->SetLeftMargin(0.15);

h_mass11[j]->SetMarkerStyle(20);
h_mass11[j]->SetMarkerColor(kBlue);
h_mass11[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "k10qQ2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_mass11[j]->SetTitle(qqq.str().c_str());
h_mass11[j]->SetTitleSize(0.13);
h_mass11[j]->GetYaxis()->SetLabelSize(0.05);
h_mass11[j]->GetXaxis()->SetLabelSize(0.06);
h_mass11[j]->GetXaxis()->SetTitle("inv mass, GeV");
h_mass11[j]->GetYaxis()->SetTitle("d#sigma/d#theta, #mub/deg");
h_mass11[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass11[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_mass11[j]->GetXaxis()->SetTitleSize(0.065);
h_mass11[j]->GetYaxis()->SetTitleSize(0.065);
h_mass11[j]->SetMinimum(0.25*h_mass11[j]->GetMinimum());
h_mass11[j]->SetMaximum(1.25*h_mass11[j]->GetMaximum());

//cout << j << " "<<h_mass1[j]->GetBinContent(1) <<" oo\n";
h_mass11[j]->Draw("e1pX0");

inv_mass11[j]->SetMarkerStyle(20);
inv_mass11[j]->SetMarkerColor(kBlack);
inv_mass11[j]->SetLineColor(kBlack);

inv_mass11[j]->Draw("pex0 e1 same");

h_fract11[j] = (TH1F*)inv_mass11[j]->Clone();
h_fract11[j]->Divide(h_mass11[j]);

c1_arr[10]->cd(j+1);
c1_arr[10]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[10]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "k10Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract11[j]->SetTitle(qqq.str().c_str());
h_fract11[j]->SetTitleSize(0.13);
h_fract11[j]->GetYaxis()->SetTitle("ratio");
h_fract11[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract11[j]->Draw("pex0 e1");
};


};
};

//---END OF DRAWING HISTOGRAMS AND RATIOS. STARTING ADDING AND AVERAGING.--------
qqq.str("");
qqq << "h_fract_sum5";
TH1F *h_fract_sum5 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[4]+1,inv_mass1[4]->GetBinLowEdge(1),inv_mass1[4]->GetBinLowEdge(theta_bins[4])+2*inv_mass1[4]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum5->Add(h_fract1[4]);
if (k==1) h_fract_sum5->Add(h_fract2[4]);
if (k==2) h_fract_sum5->Add(h_fract3[4]);
if (k==3) h_fract_sum5->Add(h_fract4[4]);
if (k==4) h_fract_sum5->Add(h_fract5[4]);
if (k==5) h_fract_sum5->Add(h_fract6[4]);
if (k==6) h_fract_sum5->Add(h_fract7[4]);
if (k==7) h_fract_sum5->Add(h_fract8[4]);
if (k==8) h_fract_sum5->Add(h_fract9[4]);
if (k==9) h_fract_sum5->Add(h_fract10[4]);
if (k==10) h_fract_sum5->Add(h_fract11[4]);

};
cout << Nb << " h\n";
c2->cd(1);
c2->cd(1)->SetBottomMargin(0.175);
c2->cd(1)->SetLeftMargin(0.175);


qqq.str("");
qqq << "W = " << 1.3125+4*0.025 <<" GeV";

h_fract_sum5->SetTitle(qqq.str().c_str());
h_fract_sum5->SetTitleSize(0.13);
h_fract_sum5->GetYaxis()->SetLabelSize(0.05);
h_fract_sum5->GetXaxis()->SetLabelSize(0.06);
h_fract_sum5->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum5->GetYaxis()->SetTitle("ratio");
h_fract_sum5->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum5->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum5->GetXaxis()->SetTitleSize(0.065);
h_fract_sum5->GetYaxis()->SetTitleSize(0.065);
h_fract_sum5->SetMarkerStyle(20);
h_fract_sum5->SetMarkerColor(kBlack);
h_fract_sum5->SetLineColor(kBlack);
h_fract_sum5->Scale(1./Nb);
h_fract_sum5->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum5->Draw("pex0 e1");


//----------------------
qqq.str("");
qqq << "h_fract_sum6";
TH1F *h_fract_sum6 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[5]+1,inv_mass1[5]->GetBinLowEdge(1),inv_mass1[5]->GetBinLowEdge(theta_bins[5])+2*inv_mass1[5]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum6->Add(h_fract1[5]);
if (k==1) h_fract_sum6->Add(h_fract2[5]);
if (k==2) h_fract_sum6->Add(h_fract3[5]);
if (k==3) h_fract_sum6->Add(h_fract4[5]);
if (k==4) h_fract_sum6->Add(h_fract5[5]);
if (k==5) h_fract_sum6->Add(h_fract6[5]);
if (k==6) h_fract_sum6->Add(h_fract7[5]);
if (k==7) h_fract_sum6->Add(h_fract8[5]);
if (k==8) h_fract_sum6->Add(h_fract9[5]);
if (k==9) h_fract_sum6->Add(h_fract10[5]);
if (k==10) h_fract_sum6->Add(h_fract11[5]);

};
cout << Nb << " h\n";
c2->cd(2);
c2->cd(2)->SetBottomMargin(0.175);
c2->cd(2)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+5*0.025 <<" GeV";

h_fract_sum6->SetTitle(qqq.str().c_str());
h_fract_sum6->SetTitleSize(0.13);
h_fract_sum6->GetYaxis()->SetLabelSize(0.05);
h_fract_sum6->GetXaxis()->SetLabelSize(0.06);
h_fract_sum6->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum6->GetYaxis()->SetTitle("ratio");
h_fract_sum6->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum6->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum6->GetXaxis()->SetTitleSize(0.065);
h_fract_sum6->GetYaxis()->SetTitleSize(0.065);
h_fract_sum6->SetMarkerStyle(20);
h_fract_sum6->SetMarkerColor(kBlack);
h_fract_sum6->SetLineColor(kBlack);
h_fract_sum6->Scale(1./Nb);
h_fract_sum6->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum6->Draw("pex0 e1");


//----------------------
qqq.str("");
qqq << "h_fract_sum7";
TH1F *h_fract_sum7 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[6]+1,inv_mass1[6]->GetBinLowEdge(1),inv_mass1[6]->GetBinLowEdge(theta_bins[6])+2*inv_mass1[6]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum7->Add(h_fract1[6]);
if (k==1) h_fract_sum7->Add(h_fract2[6]);
if (k==2) h_fract_sum7->Add(h_fract3[6]);
if (k==3) h_fract_sum7->Add(h_fract4[6]);
if (k==4) h_fract_sum7->Add(h_fract5[6]);
if (k==5) h_fract_sum7->Add(h_fract6[6]);
if (k==6) h_fract_sum7->Add(h_fract7[6]);
if (k==7) h_fract_sum7->Add(h_fract8[6]);
if (k==8) h_fract_sum7->Add(h_fract9[6]);
if (k==9) h_fract_sum7->Add(h_fract10[6]);
if (k==10) h_fract_sum7->Add(h_fract11[6]);

};
cout << Nb << " h\n";
c2->cd(3);
c2->cd(3)->SetBottomMargin(0.175);
c2->cd(3)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+6*0.025 <<" GeV";

h_fract_sum7->SetTitle(qqq.str().c_str());
h_fract_sum7->SetTitleSize(0.13);
h_fract_sum7->GetYaxis()->SetLabelSize(0.05);
h_fract_sum7->GetXaxis()->SetLabelSize(0.06);
h_fract_sum7->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum7->GetYaxis()->SetTitle("ratio");
h_fract_sum7->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum7->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum7->GetXaxis()->SetTitleSize(0.065);
h_fract_sum7->GetYaxis()->SetTitleSize(0.065);
h_fract_sum7->SetMarkerStyle(20);
h_fract_sum7->SetMarkerColor(kBlack);
h_fract_sum7->SetLineColor(kBlack);
h_fract_sum7->Scale(1./Nb);
h_fract_sum7->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum7->Draw("pex0 e1");

//----------------------
qqq.str("");
qqq << "h_fract_sum8";
TH1F *h_fract_sum8 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[7]+1,inv_mass1[7]->GetBinLowEdge(1),inv_mass1[7]->GetBinLowEdge(theta_bins[7])+2*inv_mass1[7]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum8->Add(h_fract1[7]);
if (k==1) h_fract_sum8->Add(h_fract2[7]);
if (k==2) h_fract_sum8->Add(h_fract3[7]);
if (k==3) h_fract_sum8->Add(h_fract4[7]);
if (k==4) h_fract_sum8->Add(h_fract5[7]);
if (k==5) h_fract_sum8->Add(h_fract6[7]);
if (k==6) h_fract_sum8->Add(h_fract7[7]);
if (k==7) h_fract_sum8->Add(h_fract8[7]);
if (k==8) h_fract_sum8->Add(h_fract9[7]);
if (k==9) h_fract_sum8->Add(h_fract10[7]);
if (k==10) h_fract_sum8->Add(h_fract11[7]);

};
cout << Nb << " h\n";
c2->cd(4);
c2->cd(4)->SetBottomMargin(0.175);
c2->cd(4)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+7*0.025 <<" GeV";

h_fract_sum8->SetTitle(qqq.str().c_str());
h_fract_sum8->SetTitleSize(0.13);
h_fract_sum8->GetYaxis()->SetLabelSize(0.05);
h_fract_sum8->GetXaxis()->SetLabelSize(0.06);
h_fract_sum8->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum8->GetYaxis()->SetTitle("ratio");
h_fract_sum8->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum8->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum8->GetXaxis()->SetTitleSize(0.065);
h_fract_sum8->GetYaxis()->SetTitleSize(0.065);
h_fract_sum8->SetMarkerStyle(20);
h_fract_sum8->SetMarkerColor(kBlack);
h_fract_sum8->SetLineColor(kBlack);
h_fract_sum8->Scale(1./Nb);
h_fract_sum8->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum8->Draw("pex0 e1");




//----------------------
qqq.str("");
qqq << "h_fract_sum9";
TH1F *h_fract_sum9 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[8]+1,inv_mass1[8]->GetBinLowEdge(1),inv_mass1[8]->GetBinLowEdge(theta_bins[8])+2*inv_mass1[8]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum9->Add(h_fract1[8]);
if (k==1) h_fract_sum9->Add(h_fract2[8]);
if (k==2) h_fract_sum9->Add(h_fract3[8]);
if (k==3) h_fract_sum9->Add(h_fract4[8]);
if (k==4) h_fract_sum9->Add(h_fract5[8]);
if (k==5) h_fract_sum9->Add(h_fract6[8]);
if (k==6) h_fract_sum9->Add(h_fract7[8]);
if (k==7) h_fract_sum9->Add(h_fract8[8]);
if (k==8) h_fract_sum9->Add(h_fract9[8]);
if (k==9) h_fract_sum9->Add(h_fract10[8]);
if (k==10) h_fract_sum9->Add(h_fract11[8]);

};
cout << Nb << " h\n";
c2->cd(5);
c2->cd(5)->SetBottomMargin(0.175);
c2->cd(5)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+8*0.025 <<" GeV";

h_fract_sum9->SetTitle(qqq.str().c_str());
h_fract_sum9->SetTitleSize(0.13);
h_fract_sum9->GetYaxis()->SetLabelSize(0.05);
h_fract_sum9->GetXaxis()->SetLabelSize(0.06);
h_fract_sum9->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum9->GetYaxis()->SetTitle("ratio");
h_fract_sum9->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum9->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum9->GetXaxis()->SetTitleSize(0.065);
h_fract_sum9->GetYaxis()->SetTitleSize(0.065);
h_fract_sum9->SetMarkerStyle(20);
h_fract_sum9->SetMarkerColor(kBlack);
h_fract_sum9->SetLineColor(kBlack);
h_fract_sum9->Scale(1./Nb);
h_fract_sum9->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum9->Draw("pex0 e1");




//----------------------
qqq.str("");
qqq << "h_fract_sum10";
TH1F *h_fract_sum10 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[9]+1,inv_mass1[9]->GetBinLowEdge(1),inv_mass1[9]->GetBinLowEdge(theta_bins[9])+2*inv_mass1[9]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum10->Add(h_fract1[9]);
if (k==1) h_fract_sum10->Add(h_fract2[9]);
if (k==2) h_fract_sum10->Add(h_fract3[9]);
if (k==3) h_fract_sum10->Add(h_fract4[9]);
if (k==4) h_fract_sum10->Add(h_fract5[9]);
if (k==5) h_fract_sum10->Add(h_fract6[9]);
if (k==6) h_fract_sum10->Add(h_fract7[9]);
if (k==7) h_fract_sum10->Add(h_fract8[9]);
if (k==8) h_fract_sum10->Add(h_fract9[9]);
if (k==9) h_fract_sum10->Add(h_fract10[9]);
if (k==10) h_fract_sum10->Add(h_fract11[9]);

};
cout << Nb << " h\n";
c2->cd(6);
c2->cd(6)->SetBottomMargin(0.175);
c2->cd(6)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+9*0.025 <<" GeV";

h_fract_sum10->SetTitle(qqq.str().c_str());
h_fract_sum10->SetTitleSize(0.13);
h_fract_sum10->GetYaxis()->SetLabelSize(0.05);
h_fract_sum10->GetXaxis()->SetLabelSize(0.06);
h_fract_sum10->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum10->GetYaxis()->SetTitle("ratio");
h_fract_sum10->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum10->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum10->GetXaxis()->SetTitleSize(0.065);
h_fract_sum10->GetYaxis()->SetTitleSize(0.065);
h_fract_sum10->SetMarkerStyle(20);
h_fract_sum10->SetMarkerColor(kBlack);
h_fract_sum10->SetLineColor(kBlack);
h_fract_sum10->Scale(1./Nb);
h_fract_sum10->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum10->Draw("pex0 e1");



//----------------------
qqq.str("");
qqq << "h_fract_sum11";
TH1F *h_fract_sum11 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[10]+1,inv_mass1[10]->GetBinLowEdge(1),inv_mass1[10]->GetBinLowEdge(theta_bins[10])+2*inv_mass1[10]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=10;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum11->Add(h_fract1[10]);
if (k==1) h_fract_sum11->Add(h_fract2[10]);
if (k==2) h_fract_sum11->Add(h_fract3[10]);
if (k==3) h_fract_sum11->Add(h_fract4[10]);
if (k==4) h_fract_sum11->Add(h_fract5[10]);
if (k==5) h_fract_sum11->Add(h_fract6[10]);
if (k==6) h_fract_sum11->Add(h_fract7[10]);
if (k==7) h_fract_sum11->Add(h_fract8[10]);
if (k==8) h_fract_sum11->Add(h_fract9[10]);
if (k==9) h_fract_sum11->Add(h_fract10[10]);
//if (k==10) h_fract_sum11->Add(h_fract11[10]);

};
cout << Nb << " h\n";
c2->cd(7);
c2->cd(7)->SetBottomMargin(0.175);
c2->cd(7)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+10*0.025 <<" GeV";

h_fract_sum11->SetTitle(qqq.str().c_str());
h_fract_sum11->SetTitleSize(0.13);
h_fract_sum11->GetYaxis()->SetLabelSize(0.05);
h_fract_sum11->GetXaxis()->SetLabelSize(0.06);
h_fract_sum11->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum11->GetYaxis()->SetTitle("ratio");
h_fract_sum11->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum11->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum11->GetXaxis()->SetTitleSize(0.065);
h_fract_sum11->GetYaxis()->SetTitleSize(0.065);
h_fract_sum11->SetMarkerStyle(20);
h_fract_sum11->SetMarkerColor(kBlack);
h_fract_sum11->SetLineColor(kBlack);
h_fract_sum11->Scale(1./Nb);
h_fract_sum11->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum11->Draw("pex0 e1");



//----------------------
qqq.str("");
qqq << "h_fract_sum12";
TH1F *h_fract_sum12 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[11]+1,inv_mass1[11]->GetBinLowEdge(1),inv_mass1[11]->GetBinLowEdge(theta_bins[11])+2*inv_mass1[11]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=10;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum12->Add(h_fract1[11]);
if (k==1) h_fract_sum12->Add(h_fract2[11]);
if (k==2) h_fract_sum12->Add(h_fract3[11]);
if (k==3) h_fract_sum12->Add(h_fract4[11]);
if (k==4) h_fract_sum12->Add(h_fract5[11]);
if (k==5) h_fract_sum12->Add(h_fract6[11]);
if (k==6) h_fract_sum12->Add(h_fract7[11]);
if (k==7) h_fract_sum12->Add(h_fract8[11]);
if (k==8) h_fract_sum12->Add(h_fract9[11]);
if (k==9) h_fract_sum12->Add(h_fract10[11]);
//if (k==10) h_fract_sum12->Add(h_fract11[11]);

};
cout << Nb << " h\n";
c2->cd(8);
c2->cd(8)->SetBottomMargin(0.175);
c2->cd(8)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+11*0.025 <<" GeV";

h_fract_sum12->SetTitle(qqq.str().c_str());
h_fract_sum12->SetTitleSize(0.13);
h_fract_sum12->GetYaxis()->SetLabelSize(0.05);
h_fract_sum12->GetXaxis()->SetLabelSize(0.06);
h_fract_sum12->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum12->GetYaxis()->SetTitle("ratio");
h_fract_sum12->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum12->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum12->GetXaxis()->SetTitleSize(0.065);
h_fract_sum12->GetYaxis()->SetTitleSize(0.065);
h_fract_sum12->SetMarkerStyle(20);
h_fract_sum12->SetMarkerColor(kBlack);
h_fract_sum12->SetLineColor(kBlack);
h_fract_sum12->Scale(1./Nb);
h_fract_sum12->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum12->Draw("pex0 e1");




//----------------------
qqq.str("");
qqq << "h_fract_sum13";
TH1F *h_fract_sum13 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[12]+1,inv_mass1[12]->GetBinLowEdge(1),inv_mass1[12]->GetBinLowEdge(theta_bins[12])+2*inv_mass1[12]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=9;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum13->Add(h_fract1[12]);
if (k==1) h_fract_sum13->Add(h_fract2[12]);
if (k==2) h_fract_sum13->Add(h_fract3[12]);
if (k==3) h_fract_sum13->Add(h_fract4[12]);
if (k==4) h_fract_sum13->Add(h_fract5[12]);
if (k==5) h_fract_sum13->Add(h_fract6[12]);
if (k==6) h_fract_sum13->Add(h_fract7[12]);
if (k==7) h_fract_sum13->Add(h_fract8[12]);
if (k==8) h_fract_sum13->Add(h_fract9[12]);
//if (k==9) h_fract_sum13->Add(h_fract10[12]);
//if (k==10) h_fract_sum13->Add(h_fract11[12]);

};
cout << Nb << " h\n";
c2->cd(9);
c2->cd(9)->SetBottomMargin(0.175);
c2->cd(9)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+12*0.025 <<" GeV";

h_fract_sum13->SetTitle(qqq.str().c_str());
h_fract_sum13->SetTitleSize(0.13);
h_fract_sum13->GetYaxis()->SetLabelSize(0.05);
h_fract_sum13->GetXaxis()->SetLabelSize(0.06);
h_fract_sum13->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum13->GetYaxis()->SetTitle("ratio");
h_fract_sum13->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum13->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum13->GetXaxis()->SetTitleSize(0.065);
h_fract_sum13->GetYaxis()->SetTitleSize(0.065);
h_fract_sum13->SetMarkerStyle(20);
h_fract_sum13->SetMarkerColor(kBlack);
h_fract_sum13->SetLineColor(kBlack);
h_fract_sum13->Scale(1./Nb);
h_fract_sum13->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum13->Draw("pex0 e1");



//----------------------
qqq.str("");
qqq << "h_fract_sum14";
TH1F *h_fract_sum14 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[13]+1,inv_mass1[13]->GetBinLowEdge(1),inv_mass1[13]->GetBinLowEdge(theta_bins[13])+2*inv_mass1[13]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=8;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum14->Add(h_fract1[13]);
if (k==1) h_fract_sum14->Add(h_fract2[13]);
if (k==2) h_fract_sum14->Add(h_fract3[13]);
if (k==3) h_fract_sum14->Add(h_fract4[13]);
if (k==4) h_fract_sum14->Add(h_fract5[13]);
if (k==5) h_fract_sum14->Add(h_fract6[13]);
if (k==6) h_fract_sum14->Add(h_fract7[13]);
if (k==7) h_fract_sum14->Add(h_fract8[13]);
//if (k==8) h_fract_sum14->Add(h_fract9[13]);
//if (k==9) h_fract_sum14->Add(h_fract10[13]);
//if (k==10) h_fract_sum14->Add(h_fract11[13]);

};
cout << Nb << " h\n";
c2->cd(10);
c2->cd(10)->SetBottomMargin(0.175);
c2->cd(10)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+13*0.025 <<" GeV";

h_fract_sum14->SetTitle(qqq.str().c_str());
h_fract_sum14->SetTitleSize(0.13);
h_fract_sum14->GetYaxis()->SetLabelSize(0.05);
h_fract_sum14->GetXaxis()->SetLabelSize(0.06);
h_fract_sum14->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum14->GetYaxis()->SetTitle("ratio");
h_fract_sum14->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum14->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum14->GetXaxis()->SetTitleSize(0.065);
h_fract_sum14->GetYaxis()->SetTitleSize(0.065);
h_fract_sum14->SetMarkerStyle(20);
h_fract_sum14->SetMarkerColor(kBlack);
h_fract_sum14->SetLineColor(kBlack);
h_fract_sum14->Scale(1./Nb);
h_fract_sum14->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum14->Draw("pex0 e1");



//----------------------
qqq.str("");
qqq << "h_fract_sum15";
TH1F *h_fract_sum15 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[14]+1,inv_mass1[14]->GetBinLowEdge(1),inv_mass1[14]->GetBinLowEdge(theta_bins[14])+2*inv_mass1[14]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=7;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum15->Add(h_fract1[14]);
if (k==1) h_fract_sum15->Add(h_fract2[14]);
if (k==2) h_fract_sum15->Add(h_fract3[14]);
if (k==3) h_fract_sum15->Add(h_fract4[14]);
if (k==4) h_fract_sum15->Add(h_fract5[14]);
if (k==5) h_fract_sum15->Add(h_fract6[14]);
if (k==6) h_fract_sum15->Add(h_fract7[14]);
//if (k==7) h_fract_sum15->Add(h_fract8[14]);
//if (k==8) h_fract_sum15->Add(h_fract9[14]);
//if (k==9) h_fract_sum15->Add(h_fract10[14]);
//if (k==10) h_fract_sum15->Add(h_fract11[14]);

};
cout << Nb << " h\n";
c2->cd(11);
c2->cd(11)->SetBottomMargin(0.175);
c2->cd(11)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+14*0.025 <<" GeV";

h_fract_sum15->SetTitle(qqq.str().c_str());
h_fract_sum15->SetTitleSize(0.13);
h_fract_sum15->GetYaxis()->SetLabelSize(0.05);
h_fract_sum15->GetXaxis()->SetLabelSize(0.06);
h_fract_sum15->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum15->GetYaxis()->SetTitle("ratio");
h_fract_sum15->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum15->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum15->GetXaxis()->SetTitleSize(0.065);
h_fract_sum15->GetYaxis()->SetTitleSize(0.065);
h_fract_sum15->SetMarkerStyle(20);
h_fract_sum15->SetMarkerColor(kBlack);
h_fract_sum15->SetLineColor(kBlack);
h_fract_sum15->Scale(1./Nb);
h_fract_sum15->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum15->Draw("pex0 e1");


//----------------------
qqq.str("");
qqq << "h_fract_sum16";
TH1F *h_fract_sum16 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[15]+1,inv_mass1[15]->GetBinLowEdge(1),inv_mass1[15]->GetBinLowEdge(theta_bins[15])+2*inv_mass1[15]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=7;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum16->Add(h_fract1[15]);
if (k==1) h_fract_sum16->Add(h_fract2[15]);
if (k==2) h_fract_sum16->Add(h_fract3[15]);
if (k==3) h_fract_sum16->Add(h_fract4[15]);
if (k==4) h_fract_sum16->Add(h_fract5[15]);
if (k==5) h_fract_sum16->Add(h_fract6[15]);
if (k==6) h_fract_sum16->Add(h_fract7[15]);
//if (k==7) h_fract_sum16->Add(h_fract8[15]);
//if (k==8) h_fract_sum16->Add(h_fract9[15]);
//if (k==9) h_fract_sum16->Add(h_fract10[15]);
//if (k==10) h_fract_sum16->Add(h_fract11[15]);

};
cout << Nb << " h\n";
c2->cd(12);
c2->cd(12)->SetBottomMargin(0.175);
c2->cd(12)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+15*0.025 <<" GeV";

h_fract_sum16->SetTitle(qqq.str().c_str());
h_fract_sum16->SetTitleSize(0.13);
h_fract_sum16->GetYaxis()->SetLabelSize(0.05);
h_fract_sum16->GetXaxis()->SetLabelSize(0.06);
h_fract_sum16->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum16->GetYaxis()->SetTitle("ratio");
h_fract_sum16->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum16->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum16->GetXaxis()->SetTitleSize(0.065);
h_fract_sum16->GetYaxis()->SetTitleSize(0.065);
h_fract_sum16->SetMarkerStyle(20);
h_fract_sum16->SetMarkerColor(kBlack);
h_fract_sum16->SetLineColor(kBlack);
h_fract_sum16->Scale(1./Nb);
h_fract_sum16->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum16->Draw("pex0 e1");


//----------------------
qqq.str("");
qqq << "h_fract_sum17";
TH1F *h_fract_sum17 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[16]+1,inv_mass1[16]->GetBinLowEdge(1),inv_mass1[16]->GetBinLowEdge(theta_bins[16])+2*inv_mass1[16]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=6;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum17->Add(h_fract1[16]);
if (k==1) h_fract_sum17->Add(h_fract2[16]);
if (k==2) h_fract_sum17->Add(h_fract3[16]);
if (k==3) h_fract_sum17->Add(h_fract4[16]);
if (k==4) h_fract_sum17->Add(h_fract5[16]);
if (k==5) h_fract_sum17->Add(h_fract6[16]);
//if (k==6) h_fract_sum17->Add(h_fract7[16]);
//if (k==7) h_fract_sum17->Add(h_fract8[16]);
//if (k==8) h_fract_sum17->Add(h_fract9[16]);
//if (k==9) h_fract_sum17->Add(h_fract10[16]);
//if (k==10) h_fract_sum17->Add(h_fract11[16]);

};
cout << Nb << " h\n";
c2->cd(13);
c2->cd(13)->SetBottomMargin(0.175);
c2->cd(13)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+16*0.025 <<" GeV";

h_fract_sum17->SetTitle(qqq.str().c_str());
h_fract_sum17->SetTitleSize(0.13);
h_fract_sum17->GetYaxis()->SetLabelSize(0.05);
h_fract_sum17->GetXaxis()->SetLabelSize(0.06);
h_fract_sum17->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum17->GetYaxis()->SetTitle("ratio");
h_fract_sum17->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum17->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum17->GetXaxis()->SetTitleSize(0.065);
h_fract_sum17->GetYaxis()->SetTitleSize(0.065);
h_fract_sum17->SetMarkerStyle(20);
h_fract_sum17->SetMarkerColor(kBlack);
h_fract_sum17->SetLineColor(kBlack);
h_fract_sum17->Scale(1./Nb);
h_fract_sum17->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum17->Draw("pex0 e1");


//----------------------
qqq.str("");
qqq << "h_fract_sum18";
TH1F *h_fract_sum18 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[17]+1,inv_mass1[17]->GetBinLowEdge(1),inv_mass1[17]->GetBinLowEdge(theta_bins[17])+2*inv_mass1[17]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=5;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum18->Add(h_fract1[17]);
if (k==1) h_fract_sum18->Add(h_fract2[17]);
if (k==2) h_fract_sum18->Add(h_fract3[17]);
if (k==3) h_fract_sum18->Add(h_fract4[17]);
if (k==4) h_fract_sum18->Add(h_fract5[17]);
//if (k==5) h_fract_sum18->Add(h_fract6[17]);
//if (k==6) h_fract_sum18->Add(h_fract7[17]);
//if (k==7) h_fract_sum18->Add(h_fract8[17]);
//if (k==8) h_fract_sum18->Add(h_fract9[17]);
//if (k==9) h_fract_sum18->Add(h_fract10[17]);
//if (k==10) h_fract_sum18->Add(h_fract11[17]);

};
cout << Nb << " h\n";
c2->cd(14);
c2->cd(14)->SetBottomMargin(0.175);
c2->cd(14)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+17*0.025 <<" GeV";

h_fract_sum18->SetTitle(qqq.str().c_str());
h_fract_sum18->SetTitleSize(0.13);
h_fract_sum18->GetYaxis()->SetLabelSize(0.05);
h_fract_sum18->GetXaxis()->SetLabelSize(0.06);
h_fract_sum18->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum18->GetYaxis()->SetTitle("ratio");
h_fract_sum18->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum18->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum18->GetXaxis()->SetTitleSize(0.065);
h_fract_sum18->GetYaxis()->SetTitleSize(0.065);
h_fract_sum18->SetMarkerStyle(20);
h_fract_sum18->SetMarkerColor(kBlack);
h_fract_sum18->SetLineColor(kBlack);
h_fract_sum18->Scale(1./Nb);
h_fract_sum18->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum18->Draw("pex0 e1");



//----------------------
qqq.str("");
qqq << "h_fract_sum19";
TH1F *h_fract_sum19 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[18]+1,inv_mass1[18]->GetBinLowEdge(1),inv_mass1[18]->GetBinLowEdge(theta_bins[18])+2*inv_mass1[18]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=4;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum19->Add(h_fract1[18]);
if (k==1) h_fract_sum19->Add(h_fract2[18]);
if (k==2) h_fract_sum19->Add(h_fract3[18]);
if (k==3) h_fract_sum19->Add(h_fract4[18]);
//if (k==4) h_fract_sum19->Add(h_fract5[18]);
//if (k==5) h_fract_sum19->Add(h_fract6[18]);
//if (k==6) h_fract_sum19->Add(h_fract7[18]);
//if (k==7) h_fract_sum19->Add(h_fract8[18]);
//if (k==8) h_fract_sum19->Add(h_fract9[18]);
//if (k==9) h_fract_sum19->Add(h_fract10[18]);
//if (k==10) h_fract_sum19->Add(h_fract11[18]);

};
cout << Nb << " h\n";
c2->cd(15);
c2->cd(15)->SetBottomMargin(0.175);
c2->cd(15)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+18*0.025 <<" GeV";

h_fract_sum19->SetTitle(qqq.str().c_str());
h_fract_sum19->SetTitleSize(0.13);
h_fract_sum19->GetYaxis()->SetLabelSize(0.05);
h_fract_sum19->GetXaxis()->SetLabelSize(0.06);
h_fract_sum19->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum19->GetYaxis()->SetTitle("ratio");
h_fract_sum19->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum19->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum19->GetXaxis()->SetTitleSize(0.065);
h_fract_sum19->GetYaxis()->SetTitleSize(0.065);
h_fract_sum19->SetMarkerStyle(20);
h_fract_sum19->SetMarkerColor(kBlack);
h_fract_sum19->SetLineColor(kBlack);
h_fract_sum19->Scale(1./Nb);
h_fract_sum19->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum19->Draw("pex0 e1");



//----------------------
qqq.str("");
qqq << "h_fract_sum20";
TH1F *h_fract_sum20 = new TH1F(qqq.str().c_str(),qqq.str().c_str(),theta_bins[19]+1,inv_mass1[19]->GetBinLowEdge(1),inv_mass1[19]->GetBinLowEdge(theta_bins[19])+2*inv_mass1[19]->GetBinWidth(1));
qqq.str("");

Nb = 0;
for ( Q2bin_index=1;Q2bin_index<=3;Q2bin_index++){

k = Q2bin_index - 1;

Nb = Nb +1;
if (k==0) h_fract_sum20->Add(h_fract1[19]);
if (k==1) h_fract_sum20->Add(h_fract2[19]);
if (k==2) h_fract_sum20->Add(h_fract3[19]);
//if (k==3) h_fract_sum20->Add(h_fract4[19]);
//if (k==4) h_fract_sum20->Add(h_fract5[19]);
//if (k==5) h_fract_sum20->Add(h_fract6[19]);
//if (k==6) h_fract_sum20->Add(h_fract7[19]);
//if (k==7) h_fract_sum20->Add(h_fract8[19]);
//if (k==8) h_fract_sum20->Add(h_fract9[19]);
//if (k==9) h_fract_sum20->Add(h_fract10[19]);
//if (k==10) h_fract_sum20->Add(h_fract11[19]);

};
cout << Nb << " h\n";
c2->cd(16);
c2->cd(16)->SetBottomMargin(0.175);
c2->cd(16)->SetLeftMargin(0.175);

qqq.str("");
qqq << "W = " << 1.3125+19*0.025 <<" GeV";

h_fract_sum20->SetTitle(qqq.str().c_str());
h_fract_sum20->SetTitleSize(0.13);
h_fract_sum20->GetYaxis()->SetLabelSize(0.05);
h_fract_sum20->GetXaxis()->SetLabelSize(0.06);
h_fract_sum20->GetXaxis()->SetTitle("inv mass, GeV");
h_fract_sum20->GetYaxis()->SetTitle("ratio");
h_fract_sum20->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum20->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fract_sum20->GetXaxis()->SetTitleSize(0.065);
h_fract_sum20->GetYaxis()->SetTitleSize(0.065);
h_fract_sum20->SetMarkerStyle(20);
h_fract_sum20->SetMarkerColor(kBlack);
h_fract_sum20->SetLineColor(kBlack);
h_fract_sum20->Scale(1./Nb);
h_fract_sum20->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum20->Draw("pex0 e1");



//Writing to file
/*qqq.str("");
qqq << "h_fract_theta_pim";
TH1F *h_fract_theta_pim = new TH1F(qqq.str().c_str(),qqq.str().c_str(),11, 0,180);
qqq.str("");

for (i=1;i<=11;i++){
h_fract_theta_pim->SetBinContent(i,h_fract_sum->GetBinContent(i));
h_fract_theta_pim->SetBinError(i,h_fract_sum->GetBinError(i));
};
h_fract_theta_pim->SetMarkerStyle(20);
h_fract_theta_pim->SetMarkerColor(kBlack);
h_fract_theta_pim->SetLineColor(kBlack);
h_fract_theta_pim->GetYaxis()->SetRangeUser(0.15,1.15);*/

/*TFile *file_out2 = new TFile("out_inv_mass_pim_pr.root","RECREATE");

file_out2->cd();



h_fract_sum5->Write();
h_fract_sum6->Write();
h_fract_sum7->Write();
h_fract_sum8->Write();
h_fract_sum9->Write();
h_fract_sum10->Write();
h_fract_sum11->Write();
h_fract_sum12->Write();
h_fract_sum13->Write();
h_fract_sum14->Write();
h_fract_sum15->Write();
h_fract_sum16->Write();
h_fract_sum17->Write();
h_fract_sum18->Write();
h_fract_sum19->Write();
h_fract_sum20->Write();

file_out2->Close();*/

};

