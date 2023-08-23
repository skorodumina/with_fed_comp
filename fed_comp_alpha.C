//This script compares alpha distributions for the two cross section sets: quasi-free cross sections off protons in the deuteron (Skorodumina) and free proton cross sections (Fedotov). The script plots the two cross section sets and then plots their ratios.

void fed_comp_alpha(){
ostringstream qqq;
gStyle->SetOptStat(0);
gStyle->SetTitleSize(0.07,"t"); 

TCanvas *c_arr[11];
TCanvas *c1_arr[11];

TCanvas *c2 = new TCanvas("c2","c2",0,0,500,500);

Short_t i,j,k,Q2bin_index, Nb;

Short_t nbins[12] = {21, 21, 20, 20, 19, 18, 17, 16, 14, 13, 12, 10};

Short_t alpha_bins[21] = {5, 5, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

string dummy,dummy_2,dummy_3;
string number, number1;

Float_t arr_alph_val[11][21][8];
Float_t arr_alph_xsect[11][21][8];
Float_t arr_alph_err[11][21][8];

//k - Q2 bins
//j - W bins
//i - alpha bins

Float_t fedQ2bin, fedWbin;

//Q2bin_index = 1;
//fedQ2bin = 0.425+0.05*Q2bin_index;

string file_names_alph[11][21];


TH1F *h_alph1[21];
TH1F *h_alph2[20];
TH1F *h_alph3[20];
TH1F *h_alph4[19];
TH1F *h_alph5[18];
TH1F *h_alph6[17];
TH1F *h_alph7[16];
TH1F *h_alph8[14];
TH1F *h_alph9[13];
TH1F *h_alph10[12];
TH1F *h_alph11[10];


TH1D *alpha_angle1[21];
TH1D *alpha_angle2[20];
TH1D *alpha_angle3[20];
TH1D *alpha_angle4[19];
TH1D *alpha_angle5[18];
TH1D *alpha_angle6[17];
TH1D *alpha_angle7[16];
TH1D *alpha_angle8[14];
TH1D *alpha_angle9[13];
TH1D *alpha_angle10[12];
TH1D *alpha_angle11[10];

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

qqq.str("");
qqq << "h_fract_sum";
TH1F *h_fract_sum = new TH1F(qqq.str().c_str(),qqq.str().c_str(),8, 0,360);
qqq.str("");



//Fedotov's data

for (Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

fedQ2bin = 0.425+0.05*Q2bin_index;
k = Q2bin_index - 1;

for (j=0;j<nbins[Q2bin_index];j++){

fedWbin = 1.3125+j*0.025;

qqq.str("");
if (!(k==10)) qqq << "two_pi_exp_data/Fedotov_data_Q2_0425_0975/Q2_0"<<1000.*fedQ2bin-25.<<"_0"<<1000.*fedQ2bin+25.<<"/w_"<<1000.*fedWbin-12.5<<"_"<<1000.*fedWbin+12.5<<"/xsec1d_alpha_pr.dat";

if (k==10) qqq << "two_pi_exp_data/Fedotov_data_Q2_0425_0975/Q2_0"<<1000.*fedQ2bin-25.<<"_"<<1000.*fedQ2bin+25.<<"/w_"<<1000.*fedWbin-12.5<<"_"<<1000.*fedWbin+12.5<<"/xsec1d_alpha_pr.dat";

file_names_alph[k][j] =qqq.str().c_str();

cout <<"k = "<< k << " "<< file_names_alph[k][j] <<endl;
};
};

//----------------alpha-----------------

for (Q2bin_index = 1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;
for (j=0;j<nbins[Q2bin_index];j++){
cout <<"k = "<< k << " "<< file_names_alph[k][j] <<endl;

string file=file_names_alph[k][j];
ifstream input(file.c_str());

if(input.is_open()){
for (i=1; i<=alpha_bins[j]; i++){

getline(input,number1);
number = number1.substr(0,number1.length());
dummy = number.substr(0,number.find(" "));
arr_alph_val[k][j][i-1] = atof(dummy.c_str());

dummy_2 = number.substr(dummy.length()+1,number.rfind(" "));
dummy_2 = dummy_2.substr(0,dummy_2.find(" "));
arr_alph_xsect[k][j][i-1] =  atof(dummy_2.c_str());

dummy_3 = number.substr(dummy.length()+dummy_2.length()+2,number.rfind(" "));
dummy_3 =dummy_3.substr(0,dummy_3.find(" "));
arr_alph_err[k][j][i-1] = atof(dummy_3.c_str());

cout <<"k = "<<k<<", j = "<<j<<", i = "<<i<<" "<<arr_alph_val[k][j][i-1] << "   "<<arr_alph_xsect[k][j][i-1]<<" "<<arr_alph_err[k][j][i-1]<< "\n";
};
};
input.close();
};
};



for (Q2bin_index = 1;Q2bin_index<=11;Q2bin_index++){
k = Q2bin_index - 1;
for (Short_t j=0; j<nbins[Q2bin_index]; j++){

 qqq.str("");
if (k==0) qqq << "h_alpha_angle1_" << j;
if (k==0) h_alph1[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==1) qqq << "h_alpha_angle2_" << j;
if (k==1) h_alph2[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==2) qqq << "h_alpha_angle3_" << j;
if (k==2) h_alph3[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==3) qqq << "h_alpha_angle4_" << j;
if (k==3) h_alph4[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==4) qqq << "h_alpha_angle5_" << j;
if (k==4) h_alph5[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==5) qqq << "h_alpha_angle6_" << j;
if (k==5) h_alph6[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==6) qqq << "h_alpha_angle7_" << j;
if (k==6) h_alph7[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==7) qqq << "h_alpha_angle8_" << j;
if (k==7) h_alph8[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==8) qqq << "h_alpha_angle9_" << j;
if (k==8) h_alph9[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==9) qqq << "h_alpha_angle10_" << j;
if (k==9) h_alph10[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);
if (k==10) qqq << "h_alpha_angle11_" << j;
if (k==10) h_alph11[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),alpha_bins[j], 0,360);

 qqq.str("");
};
};

for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

qqq.str("");
qqq << "c_arr" << k+1;
c_arr[k] = new TCanvas (qqq.str().c_str(),qqq.str().c_str(),0,0,1000,1000);
c_arr[k]->Divide(5,4);

qqq.str("");
qqq << "c1_arr" << k+1;
c1_arr[k] = new TCanvas (qqq.str().c_str(),qqq.str().c_str(),0,0,1000,1000);
c1_arr[k]->Divide(5,4);

};

for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){
k = Q2bin_index - 1;

for (Short_t j=0; j<nbins[Q2bin_index]; j++){

for (i=1; i<=alpha_bins[j]; i++){

if (k==0)  h_alph1[j]->Fill(arr_alph_val[0][j][i-1], arr_alph_xsect[0][j][i-1]);
if (k==0)  h_alph1[j]->SetBinError(h_alph1[j]->FindBin(arr_alph_val[0][j][i-1]),arr_alph_err[0][j][i-1]);  
cout << Q2bin_index <<" "<< j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
if (k==1)   h_alph2[j]->Fill(arr_alph_val[1][j][i-1], arr_alph_xsect[1][j][i-1]);
if (k==1)   h_alph2[j]->SetBinError(h_alph2[j]->FindBin(arr_alph_val[1][j][i-1]),arr_alph_err[1][j][i-1]);  

if (k==2)   h_alph3[j]->Fill(arr_alph_val[2][j][i-1], arr_alph_xsect[2][j][i-1]);
if (k==2)   h_alph3[j]->SetBinError(h_alph3[j]->FindBin(arr_alph_val[2][j][i-1]),arr_alph_err[2][j][i-1]);  

if (k==3)   h_alph4[j]->Fill(arr_alph_val[3][j][i-1], arr_alph_xsect[3][j][i-1]);
if (k==3)   h_alph4[j]->SetBinError(h_alph4[j]->FindBin(arr_alph_val[3][j][i-1]),arr_alph_err[3][j][i-1]);  

if (k==4)   h_alph5[j]->Fill(arr_alph_val[4][j][i-1], arr_alph_xsect[4][j][i-1]);
if (k==4)   h_alph5[j]->SetBinError(h_alph5[j]->FindBin(arr_alph_val[4][j][i-1]),arr_alph_err[4][j][i-1]);  

if (k==5)   h_alph6[j]->Fill(arr_alph_val[5][j][i-1], arr_alph_xsect[5][j][i-1]);
if (k==5)   h_alph6[j]->SetBinError(h_alph6[j]->FindBin(arr_alph_val[5][j][i-1]),arr_alph_err[5][j][i-1]);  

if (k==6)   h_alph7[j]->Fill(arr_alph_val[6][j][i-1], arr_alph_xsect[6][j][i-1]);
if (k==6)   h_alph7[j]->SetBinError(h_alph7[j]->FindBin(arr_alph_val[6][j][i-1]),arr_alph_err[6][j][i-1]);  

if (k==7)   h_alph8[j]->Fill(arr_alph_val[7][j][i-1], arr_alph_xsect[7][j][i-1]);
if (k==7)   h_alph8[j]->SetBinError(h_alph8[j]->FindBin(arr_alph_val[7][j][i-1]),arr_alph_err[7][j][i-1]);  

if (k==8)   h_alph9[j]->Fill(arr_alph_val[8][j][i-1], arr_alph_xsect[8][j][i-1]);
if (k==8)   h_alph9[j]->SetBinError(h_alph9[j]->FindBin(arr_alph_val[8][j][i-1]),arr_alph_err[8][j][i-1]);  

if (k==9)   h_alph10[j]->Fill(arr_alph_val[9][j][i-1], arr_alph_xsect[9][j][i-1]);
if (k==9)   h_alph10[j]->SetBinError(h_alph10[j]->FindBin(arr_alph_val[9][j][i-1]),arr_alph_err[9][j][i-1]);  

if (k==10)   h_alph11[j]->Fill(arr_alph_val[10][j][i-1], arr_alph_xsect[10][j][i-1]);
if (k==10)   h_alph11[j]->SetBinError(h_alph11[j]->FindBin(arr_alph_val[10][j][i-1]),arr_alph_err[10][j][i-1]);

};

};
};

//alpha_p "/h1prj_alpha_PIpPIm_pipf_bin_corr";
//alpha_pim "/h2prj_alpha_PPIp_piPIm_bin_corr";
//alpha_pip"/h3prj_alpha_PPIm_piPIp_bin_corr";

//Skorodumina's data
TFile *MyFile1 = new TFile("out_fin_2021.root","READ");
MyFile1->cd();

for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

fedQ2bin = 0.425+0.05*Q2bin_index;
k = Q2bin_index - 1;

for (Short_t j=0; j<nbins[Q2bin_index]; j++){
qqq.str("");
qqq << "q2_" << fedQ2bin << "/w_" << 1.3125+0.025*j << "/h1prj_alpha_PIpPIm_pipf_bin_corr";
//cout <<qqq.str().c_str()<<" rr\n";
if (k==0) gDirectory->GetObject(qqq.str().c_str(),alpha_angle1[j]);
if (k==1) gDirectory->GetObject(qqq.str().c_str(),alpha_angle2[j]);
if (k==2) gDirectory->GetObject(qqq.str().c_str(),alpha_angle3[j]);
if (k==3) gDirectory->GetObject(qqq.str().c_str(),alpha_angle4[j]);
if (k==4) gDirectory->GetObject(qqq.str().c_str(),alpha_angle5[j]);
if (k==5) gDirectory->GetObject(qqq.str().c_str(),alpha_angle6[j]);
if (k==6) gDirectory->GetObject(qqq.str().c_str(),alpha_angle7[j]);
if (k==7) gDirectory->GetObject(qqq.str().c_str(),alpha_angle8[j]);
if (k==8) gDirectory->GetObject(qqq.str().c_str(),alpha_angle9[j]);
if (k==9) gDirectory->GetObject(qqq.str().c_str(),alpha_angle10[j]);
if (k==10) gDirectory->GetObject(qqq.str().c_str(),alpha_angle11[j]);

qqq.str("");
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

h_alph1[j]->SetMarkerStyle(20);
h_alph1[j]->SetMarkerColor(kBlue);
h_alph1[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph1[j]->SetTitle(qqq.str().c_str());
h_alph1[j]->SetTitleSize(0.13);
h_alph1[j]->GetYaxis()->SetLabelSize(0.05);
h_alph1[j]->GetXaxis()->SetLabelSize(0.06);
h_alph1[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph1[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph1[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph1[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph1[j]->GetXaxis()->SetTitleSize(0.065);
h_alph1[j]->GetYaxis()->SetTitleSize(0.065);
h_alph1[j]->SetMinimum(0.25*h_alph1[j]->GetMinimum());
h_alph1[j]->SetMaximum(1.25*h_alph1[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph1[j]->Draw("e1pX0");

alpha_angle1[j]->SetMarkerStyle(20);
alpha_angle1[j]->SetMarkerColor(kBlack);
alpha_angle1[j]->SetLineColor(kBlack);

alpha_angle1[j]->Draw("pex0 e1 same");


h_fract1[j] = (TH1F*)alpha_angle1[j]->Clone();
h_fract1[j]->Divide(h_alph1[j]);

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

h_alph2[j]->SetMarkerStyle(20);
h_alph2[j]->SetMarkerColor(kBlue);
h_alph2[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph2[j]->SetTitle(qqq.str().c_str());
h_alph2[j]->SetTitleSize(0.13);
h_alph2[j]->GetYaxis()->SetLabelSize(0.05);
h_alph2[j]->GetXaxis()->SetLabelSize(0.06);
h_alph2[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph2[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph2[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph2[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph2[j]->GetXaxis()->SetTitleSize(0.065);
h_alph2[j]->GetYaxis()->SetTitleSize(0.065);
h_alph2[j]->SetMinimum(0.25*h_alph2[j]->GetMinimum());
h_alph2[j]->SetMaximum(1.25*h_alph2[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph2[j]->Draw("e1pX0");

alpha_angle2[j]->SetMarkerStyle(20);
alpha_angle2[j]->SetMarkerColor(kBlack);
alpha_angle2[j]->SetLineColor(kBlack);

alpha_angle2[j]->Draw("pex0 e1 same");

h_fract2[j] = (TH1F*)alpha_angle2[j]->Clone();
h_fract2[j]->Divide(h_alph2[j]);

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

h_alph3[j]->SetMarkerStyle(20);
h_alph3[j]->SetMarkerColor(kBlue);
h_alph3[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph3[j]->SetTitle(qqq.str().c_str());
h_alph3[j]->SetTitleSize(0.13);
h_alph3[j]->GetYaxis()->SetLabelSize(0.05);
h_alph3[j]->GetXaxis()->SetLabelSize(0.06);
h_alph3[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph3[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph3[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph3[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph3[j]->GetXaxis()->SetTitleSize(0.065);
h_alph3[j]->GetYaxis()->SetTitleSize(0.065);
h_alph3[j]->SetMinimum(0.25*h_alph3[j]->GetMinimum());
h_alph3[j]->SetMaximum(1.25*h_alph3[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph3[j]->Draw("e1pX0");

alpha_angle3[j]->SetMarkerStyle(20);
alpha_angle3[j]->SetMarkerColor(kBlack);
alpha_angle3[j]->SetLineColor(kBlack);

alpha_angle3[j]->Draw("pex0 e1 same");

h_fract3[j] = (TH1F*)alpha_angle3[j]->Clone();
h_fract3[j]->Divide(h_alph3[j]);

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

h_alph4[j]->SetMarkerStyle(20);
h_alph4[j]->SetMarkerColor(kBlue);
h_alph4[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph4[j]->SetTitle(qqq.str().c_str());
h_alph4[j]->SetTitleSize(0.13);
h_alph4[j]->GetYaxis()->SetLabelSize(0.05);
h_alph4[j]->GetXaxis()->SetLabelSize(0.06);
h_alph4[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph4[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph4[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph4[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph4[j]->GetXaxis()->SetTitleSize(0.065);
h_alph4[j]->GetYaxis()->SetTitleSize(0.065);
h_alph4[j]->SetMinimum(0.25*h_alph4[j]->GetMinimum());
h_alph4[j]->SetMaximum(1.25*h_alph4[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph4[j]->Draw("e1pX0");

alpha_angle4[j]->SetMarkerStyle(20);
alpha_angle4[j]->SetMarkerColor(kBlack);
alpha_angle4[j]->SetLineColor(kBlack);

alpha_angle4[j]->Draw("pex0 e1 same");


h_fract4[j] = (TH1F*)alpha_angle4[j]->Clone();
h_fract4[j]->Divide(h_alph4[j]);

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

h_alph5[j]->SetMarkerStyle(20);
h_alph5[j]->SetMarkerColor(kBlue);
h_alph5[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph5[j]->SetTitle(qqq.str().c_str());
h_alph5[j]->SetTitleSize(0.13);
h_alph5[j]->GetYaxis()->SetLabelSize(0.05);
h_alph5[j]->GetXaxis()->SetLabelSize(0.06);
h_alph5[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph5[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph5[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph5[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph5[j]->GetXaxis()->SetTitleSize(0.065);
h_alph5[j]->GetYaxis()->SetTitleSize(0.065);
h_alph5[j]->SetMinimum(0.25*h_alph5[j]->GetMinimum());
h_alph5[j]->SetMaximum(1.25*h_alph5[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph5[j]->Draw("e1pX0");

alpha_angle5[j]->SetMarkerStyle(20);
alpha_angle5[j]->SetMarkerColor(kBlack);
alpha_angle5[j]->SetLineColor(kBlack);

alpha_angle5[j]->Draw("pex0 e1 same");

h_fract5[j] = (TH1F*)alpha_angle5[j]->Clone();
h_fract5[j]->Divide(h_alph5[j]);

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

h_alph6[j]->SetMarkerStyle(20);
h_alph6[j]->SetMarkerColor(kBlue);
h_alph6[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph6[j]->SetTitle(qqq.str().c_str());
h_alph6[j]->SetTitleSize(0.13);
h_alph6[j]->GetYaxis()->SetLabelSize(0.05);
h_alph6[j]->GetXaxis()->SetLabelSize(0.06);
h_alph6[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph6[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph6[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph6[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph6[j]->GetXaxis()->SetTitleSize(0.065);
h_alph6[j]->GetYaxis()->SetTitleSize(0.065);
h_alph6[j]->SetMinimum(0.25*h_alph6[j]->GetMinimum());
h_alph6[j]->SetMaximum(1.25*h_alph6[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph6[j]->Draw("e1pX0");

alpha_angle6[j]->SetMarkerStyle(20);
alpha_angle6[j]->SetMarkerColor(kBlack);
alpha_angle6[j]->SetLineColor(kBlack);

alpha_angle6[j]->Draw("pex0 e1 same");

h_fract6[j] = (TH1F*)alpha_angle6[j]->Clone();
h_fract6[j]->Divide(h_alph6[j]);

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

h_alph7[j]->SetMarkerStyle(20);
h_alph7[j]->SetMarkerColor(kBlue);
h_alph7[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph7[j]->SetTitle(qqq.str().c_str());
h_alph7[j]->SetTitleSize(0.13);
h_alph7[j]->GetYaxis()->SetLabelSize(0.05);
h_alph7[j]->GetXaxis()->SetLabelSize(0.06);
h_alph7[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph7[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph7[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph7[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph7[j]->GetXaxis()->SetTitleSize(0.065);
h_alph7[j]->GetYaxis()->SetTitleSize(0.065);
h_alph7[j]->SetMinimum(0.25*h_alph7[j]->GetMinimum());
h_alph7[j]->SetMaximum(1.25*h_alph7[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph7[j]->Draw("e1pX0");

alpha_angle7[j]->SetMarkerStyle(20);
alpha_angle7[j]->SetMarkerColor(kBlack);
alpha_angle7[j]->SetLineColor(kBlack);

alpha_angle7[j]->Draw("pex0 e1 same");

h_fract7[j] = (TH1F*)alpha_angle7[j]->Clone();
h_fract7[j]->Divide(h_alph7[j]);

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

h_alph8[j]->SetMarkerStyle(20);
h_alph8[j]->SetMarkerColor(kBlue);
h_alph8[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph8[j]->SetTitle(qqq.str().c_str());
h_alph8[j]->SetTitleSize(0.13);
h_alph8[j]->GetYaxis()->SetLabelSize(0.05);
h_alph8[j]->GetXaxis()->SetLabelSize(0.06);
h_alph8[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph8[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph8[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph8[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph8[j]->GetXaxis()->SetTitleSize(0.065);
h_alph8[j]->GetYaxis()->SetTitleSize(0.065);
h_alph8[j]->SetMinimum(0.25*h_alph8[j]->GetMinimum());
h_alph8[j]->SetMaximum(1.25*h_alph8[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph8[j]->Draw("e1pX0");

alpha_angle8[j]->SetMarkerStyle(20);
alpha_angle8[j]->SetMarkerColor(kBlack);
alpha_angle8[j]->SetLineColor(kBlack);

alpha_angle8[j]->Draw("pex0 e1 same");

h_fract8[j] = (TH1F*)alpha_angle8[j]->Clone();
h_fract8[j]->Divide(h_alph8[j]);

c1_arr[7]->cd(j+1);
c1_arr[7]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[7]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
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

h_alph9[j]->SetMarkerStyle(20);
h_alph9[j]->SetMarkerColor(kBlue);
h_alph9[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph9[j]->SetTitle(qqq.str().c_str());
h_alph9[j]->SetTitleSize(0.13);
h_alph9[j]->GetYaxis()->SetLabelSize(0.05);
h_alph9[j]->GetXaxis()->SetLabelSize(0.06);
h_alph9[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph9[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph9[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph9[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph9[j]->GetXaxis()->SetTitleSize(0.065);
h_alph9[j]->GetYaxis()->SetTitleSize(0.065);
h_alph9[j]->SetMinimum(0.25*h_alph9[j]->GetMinimum());
h_alph9[j]->SetMaximum(1.25*h_alph9[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph9[j]->Draw("e1pX0");

alpha_angle9[j]->SetMarkerStyle(20);
alpha_angle9[j]->SetMarkerColor(kBlack);
alpha_angle9[j]->SetLineColor(kBlack);

alpha_angle9[j]->Draw("pex0 e1 same");

h_fract9[j] = (TH1F*)alpha_angle9[j]->Clone();
h_fract9[j]->Divide(h_alph9[j]);

c1_arr[8]->cd(j+1);
c1_arr[8]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[8]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
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

h_alph10[j]->SetMarkerStyle(20);
h_alph10[j]->SetMarkerColor(kBlue);
h_alph10[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph10[j]->SetTitle(qqq.str().c_str());
h_alph10[j]->SetTitleSize(0.13);
h_alph10[j]->GetYaxis()->SetLabelSize(0.05);
h_alph10[j]->GetXaxis()->SetLabelSize(0.06);
h_alph10[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph10[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph10[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph10[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph10[j]->GetXaxis()->SetTitleSize(0.065);
h_alph10[j]->GetYaxis()->SetTitleSize(0.065);
h_alph10[j]->SetMinimum(0.25*h_alph10[j]->GetMinimum());
h_alph10[j]->SetMaximum(1.25*h_alph10[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph10[j]->Draw("e1pX0");

alpha_angle10[j]->SetMarkerStyle(20);
alpha_angle10[j]->SetMarkerColor(kBlack);
alpha_angle10[j]->SetLineColor(kBlack);

alpha_angle10[j]->Draw("pex0 e1 same");

h_fract10[j] = (TH1F*)alpha_angle10[j]->Clone();
h_fract10[j]->Divide(h_alph10[j]);

c1_arr[9]->cd(j+1);
c1_arr[9]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[9]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
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

h_alph11[j]->SetMarkerStyle(20);
h_alph11[j]->SetMarkerColor(kBlue);
h_alph11[j]->SetLineColor(kBlue);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";

h_alph11[j]->SetTitle(qqq.str().c_str());
h_alph11[j]->SetTitleSize(0.13);
h_alph11[j]->GetYaxis()->SetLabelSize(0.05);
h_alph11[j]->GetXaxis()->SetLabelSize(0.06);
h_alph11[j]->GetXaxis()->SetTitle("#alpha_{#pi^{-}}, deg");
h_alph11[j]->GetYaxis()->SetTitle("d#sigma/d#alpha, #mub/deg");
h_alph11[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph11[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_alph11[j]->GetXaxis()->SetTitleSize(0.065);
h_alph11[j]->GetYaxis()->SetTitleSize(0.065);
h_alph11[j]->SetMinimum(0.25*h_alph11[j]->GetMinimum());
h_alph11[j]->SetMaximum(1.25*h_alph11[j]->GetMaximum());

//cout << j << " "<<h_alph1[j]->GetBinContent(1) <<" oo\n";
h_alph11[j]->Draw("e1pX0");

alpha_angle11[j]->SetMarkerStyle(20);
alpha_angle11[j]->SetMarkerColor(kBlack);
alpha_angle11[j]->SetLineColor(kBlack);

alpha_angle11[j]->Draw("pex0 e1 same");

h_fract11[j] = (TH1F*)alpha_angle11[j]->Clone();
h_fract11[j]->Divide(h_alph11[j]);

c1_arr[10]->cd(j+1);
c1_arr[10]->cd(j+1)->SetBottomMargin(0.15);
c1_arr[10]->cd(j+1)->SetLeftMargin(0.15);

qqq.str("");
qqq << "Q2 = "<<0.425+0.05*(k+1) << ", W = " << 1.3125+j*0.025 <<" GeV";
h_fract11[j]->SetTitle(qqq.str().c_str());
h_fract11[j]->SetTitleSize(0.13);
h_fract11[j]->GetYaxis()->SetTitle("ratio");
h_fract11[j]->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract11[j]->Draw("pex0 e1");
};



};
};

// Averaging the ratio
Nb = 0;

for ( Q2bin_index=1;Q2bin_index<=11;Q2bin_index++){

k = Q2bin_index - 1;

for (Short_t j=4; j<nbins[Q2bin_index]; j++){
Nb = Nb +1;
if (k==0) h_fract_sum->Add(h_fract1[j]);
if (k==1) h_fract_sum->Add(h_fract2[j]);
if (k==2) h_fract_sum->Add(h_fract3[j]);
if (k==3) h_fract_sum->Add(h_fract4[j]);
if (k==4) h_fract_sum->Add(h_fract5[j]);
if (k==5) h_fract_sum->Add(h_fract6[j]);
if (k==6) h_fract_sum->Add(h_fract7[j]);
if (k==7) h_fract_sum->Add(h_fract8[j]);
if (k==8) h_fract_sum->Add(h_fract9[j]);
if (k==9) h_fract_sum->Add(h_fract10[j]);
if (k==10) h_fract_sum->Add(h_fract11[j]);



};
};


cout << Nb << " h\n";
c2->cd();
h_fract_sum->SetMarkerStyle(20);
h_fract_sum->SetMarkerColor(kBlack);
h_fract_sum->SetLineColor(kBlack);
h_fract_sum->Scale(1./Nb);
h_fract_sum->GetYaxis()->SetRangeUser(0.15,1.15);
h_fract_sum->Draw("pex0 e1");

//Writing to file
/*
qqq.str("");
qqq << "h_fract_alpha_p";
TH1F *h_fract_alpha_p = new TH1F(qqq.str().c_str(),qqq.str().c_str(),8, 0,360);
qqq.str("");

for (i=1;i<=8;i++){
h_fract_alpha_p->SetBinContent(i,h_fract_sum->GetBinContent(i));
h_fract_alpha_p->SetBinError(i,h_fract_sum->GetBinError(i));
};
h_fract_alpha_p->SetMarkerStyle(20);
h_fract_alpha_p->SetMarkerColor(kBlack);
h_fract_alpha_p->SetLineColor(kBlack);
h_fract_alpha_p->GetYaxis()->SetRangeUser(0.15,1.15);

TFile *file_out2 = new TFile("out_alpha_p.root","RECREATE");

file_out2->cd();

h_fract_alpha_p ->Write();

file_out2->Close();*/

};

