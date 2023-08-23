//This script compares two sets of integral cross sections: quasi-free cross sections off protons in the deuteron (Skorodumina) and free proton cross sections (Fedotov). The script plots the two cross section sets and then plots their ratios. Then, the script fits the ratios with polynomials.


void with_fed_comp2(){
ostringstream qqq;
gStyle->SetOptStat(0);
gStyle->SetTitleSize(0.07,"t"); 
TCanvas *c = new TCanvas("c","c",0,0,1000,1000);
c->Divide(4,3);

TH2D *q2vsw = new TH2D("q2vsw","q2vsw",21,1.3,1.825,12,0.4,1.);

TCanvas *c1 = new TCanvas("c1","c1",0,0,800,600);
c1->Divide(4,3);

gStyle->SetPadBorderMode(0);
gStyle->SetFrameBorderMode(0);
Float_t small = 1e-5;

c1->cd();
  Double_t W  = 0.24;          // Pad Width
   Int_t    Nx = 4;            // Number of pads along X
   Double_t Xm = (1-(Nx*W))/2; // X Margin
   Double_t dw = (W*0.1)/4;
   Double_t rshift = 0.02;

   TPad *pp1 = new TPad("pp1", "pp1", Xm, 0.65, Xm+W+dw+rshift, 0.95, 0, 0, 0);
   pp1->SetRightMargin(0);
   pp1->Draw();

   TPad *pp2 = new TPad("pp2", "pp2", Xm+W+dw+rshift, 0.65, Xm+2*W-dw+rshift, 0.95, 0, 0, 0);
   pp2->SetRightMargin(0);
   pp2->SetLeftMargin(0);
   pp2->Draw();

   TPad *pp3 = new TPad("pp3", "pp3", Xm+2*W-dw+rshift, 0.65, Xm+3*W+rshift, 0.95, 0, 0, 0);  
   pp3->SetRightMargin(0);
   pp3->SetLeftMargin(0);
   pp3->Draw();
   
   TPad *pp4 = new TPad("pp4", "pp4", Xm+3*W-dw+rshift, 0.65, Xm+4*W+rshift, 0.95, 0, 0, 0);  
   pp4->SetLeftMargin(0);
   pp4->Draw();   
   
   TPad *pp5 = new TPad("pp5", "pp5", Xm, 0.35, Xm+W+dw+rshift, 0.65, 0, 0, 0);
   pp5->SetTopMargin(0);
   pp5->SetRightMargin(0);
   pp5->SetLeftMargin(0);
   pp5->Draw();  
   
   TPad *pp6 = new TPad("p6p", "pp6", Xm+W+dw+rshift, 0.35, Xm+2*W-dw+rshift, 0.65, 0, 0, 0);
   pp6->SetRightMargin(0);
   pp6->SetLeftMargin(0);
   pp6->Draw();

   TPad *pp7 = new TPad("pp7", "pp7", Xm+2*W-dw+rshift, 0.35, Xm+3*W+rshift, 0.65, 0, 0, 0);  
   pp7->SetRightMargin(0);
   pp7->SetLeftMargin(0);
   pp7->Draw();
   
   TPad *pp8 = new TPad("pp8", "pp8", Xm+3*W-dw+rshift, 0.35, Xm+4*W+rshift, 0.65, 0, 0, 0);  
   pp8->SetLeftMargin(0);
   pp8->Draw();       


   TPad *pp9 = new TPad("pp9", "pp9", Xm, 0.0, Xm+W+dw+rshift, 0.35, 0, 0, 0);
   pp9->SetTopMargin(0);
   pp9->SetRightMargin(0);
   pp9->SetLeftMargin(0);
   pp9->Draw();  
   
   TPad *pp10 = new TPad("pp10", "pp10", Xm+W+dw+rshift, 0.0, Xm+2*W-dw+rshift, 0.35, 0, 0, 0);
   pp10->SetRightMargin(0);
   pp10->SetLeftMargin(0);
   pp10->Draw();

   TPad *pp11 = new TPad("pp11", "pp11", Xm+2*W-dw+rshift, 0.0, Xm+3*W+rshift, 0.35, 0, 0, 0);  
   pp11->SetRightMargin(0);
   pp11->SetLeftMargin(0);
   pp11->Draw();
   
   TPad *pp12 = new TPad("pp12", "pp12", Xm+3*W-dw+rshift, 0.0, Xm+4*W+rshift, 0.35, 0, 0, 0);  
   pp12->SetLeftMargin(0);
   pp12->Draw();   




Float_t nbins[21], wmax[12];
Short_t j,k;

Float_t p0,p1,p2,p3,p4;


nbins[0] = 21;
nbins[1] = 21;
nbins[2] = 20;
nbins[3] = 20;
nbins[4] = 19;
nbins[5] = 18;
nbins[6] = 17;
nbins[7] = 16;
nbins[8] = 14;
nbins[9] = 13;
nbins[10] = 12;
nbins[11] = 10;


TH1D *h_skor_sect[12];
TH1F *h_fed_int[12];
TH1F *h_fract[12];

Float_t Wmax[21] = {1.825, 1.825, 1.8, 1.8, 1.775, 1.75, 1.725, 1.7, 1.65, 1.625, 1.6, 1.55};



for (j=0;j<=11;j++){

wmax[j] = 1.3 + 0.025*nbins[j];

qqq.str("");
qqq << "h_fed_int_"<<1000*(0.425 + 0.05*j);
h_fed_int[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),21, 1.3,1.825);

qqq.str("");
qqq << "h_skor_int_"<<1000*(0.425 + 0.05*j);
h_skor_sect[j] = new TH1D(qqq.str().c_str(),qqq.str().c_str(),21, 1.3,1.825);

qqq.str("");
qqq << "h_fract_"<<1000*(0.425 + 0.05*j);
h_fract[j] = new TH1F(qqq.str().c_str(),qqq.str().c_str(),21, 1.3,1.825);
};


//Fedotov's cross sections
Float_t sect_arr[12][21] = {{0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,28.73372738,31.07432156,32.09708018,31.87136738,31.39467620,27.94215146,23.41085314,21.21868667,19.50157538,},
{2.24456101,4.86828652,9.30590346,14.66355443,19.10508304,22.03200180,25.02192859,28.08476339,28.63642928,28.77899211,28.24667938,27.52122060,26.36379735,27.02975974,28.48720350,29.13204808,28.62103155 ,25.66245424 ,21.69089852 ,19.03784960, 18.43931013},
{1.92519249,4.42511771,8.68537930,12.98864485,17.25725926,19.85309350,22.49812137,25.69130638,26.00105775,25.65104915,24.28424214,23.96802285,24.44193028,25.15709709,25.86192310,26.83118400,27.02993263,23.93645690,19.64490342,17.70953304,0.},
{1.52889494,3.92032807,7.31529503,10.96878655,15.49631957,18.26304608,20.39584945,23.45835519,23.77439058,24.31629948,22.80124386,23.01466846,23.10124672,23.38091605,23.76854363,24.77947742,24.09825415,21.38255390,18.14594977,16.68543821,0.},
{1.49750142,3.49068653,6.99802603,10.82386085,14.43484195,16.48888904,19.39228104,22.77656953,22.99832658,22.81167885,21.42327970,20.74632385,20.27643859,20.44034156,21.08369525,22.69107640,23.18565616,20.92022048,17.94164957,0.,0.},
{1.52898571,3.04683941,6.29239134,10.03618871,13.16525060,15.29371473,17.55706093,20.71167518,21.00663745,19.70254246,18.64109111,17.97156549,18.25096276,19.39484124,20.65146542,22.14818086,22.46562441,20.12498555,0.,0.,0.},
{1.26087112,3.14801982,6.14365918,9.24550795,11.87196854,13.79729098,15.33473331,17.73700518,17.83213782,18.17654370,17.53168155,18.00475282,17.90855895,18.23015465,19.60273536,20.26443586,20.00019276,0.,0.,0.,0.},
{1.40655000,3.01555804,4.87809250,7.76635296,9.76363828,11.96772766,14.33159670,16.82717121,18.02877967,18.20573680,16.89778742,16.56975434,16.38756731,17.18331868,17.37425914,17.90013558,0.,0.,0.,0.,0.},
{1.06795877,2.33099577,4.53514034,7.14730297,9.88141122,12.22745591,13.34885766,16.16726961,16.52361249,16.56005724,15.36408992,15.14495525,14.90385512,14.49698749,0.,0.,0.,0.,0.,0.,0.},
{1.20380418,2.60010707,4.66229575,6.95715595,9.45345963,11.03780266,12.28094890,14.92110427,15.96600553,15.16460602,14.22158051,13.57907294,13.99464450,0.,0.,0.,0.,0.,0.,0.,0.},
{0.91725239,2.45359746,4.34547400,6.50674016,8.53766389,10.36210768,12.24614881,13.92669942,14.04868456,14.36607102,13.02980318,13.22164690,0.,0.,0.,0.,0.,0.,0.,0.,0.},
{1.06342466,2.05073643,3.79480919,6.59312779,7.66891597,8.83682443,10.29158646,12.92307689,13.17754339,13.90896423,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.}};


//Uncertainties for Fedotov's cross sections.
Float_t sect_arr_err[12][21] = {{0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.41886006,0.46354023,0.43989993,0.43669075,0.39521372,0.34698458,0.29157176,0.27449892,0.28995491},
{0.14266373,0.21334193,0.23616125,0.31326514,0.38498155,0.37984277,0.34725622,0.45491603,0.42004583,0.46429970,0.43406599,0.40969658,0.35576299,0.37133331,0.37502400,0.35796100,0.33709045,0.31297814,0.26392720,0.27652043,0.23819146},
{0.09324980,0.15528731,0.24743641,0.28639473,0.33647428,0.32991817,0.37804256,0.36563671,0.37639431,0.39710837,0.39083155,0.41471375,0.30866083,
0.31703072,0.32701551,0.34826002,0.29332430,0.26930010,0.31611766,0.22260891,0.},
{0.07845010,0.14144860,0.18721629,0.32495560,0.25814519,0.29056268,0.27405980,0.37850209,0.36400390,0.34792152,0.32440682,0.32563080,0.29930483,0.30470779,0.29827706,0.28861122,0.31520132,0.26539811,0.25740955,0.25033541,0.},
{0.08898758,0.15181463,0.16185900,0.23540458,0.24294600,0.24863561,0.25077122,0.31548676,0.35140322,0.40193970,0.34020021,0.29741709,0.28041526,0.30719049,0.28164301,0.34254657,0.32590717,0.29693689,0.26742342,0.,0.},
{0.07859543,0.14220383,0.17952532,0.22163349,0.24095056,0.24779953,0.32094845,0.32402571,0.30559733,0.32811424,0.29418667,0.30956211,0.30238838,0.33212985,0.29290208,0.32746579,0.31257100,0.30645150,0.,0.,0.},
{0.09424920,0.16643891,0.16098381,0.21753498,0.24541109,0.26342482,0.25237749,0.33251353,0.29220789,0.36671870,0.32228651,0.32671103,0.34285879,0.32915142,0.33158231,0.38006936,0.33014179,0.,0.,0.,0.},
{0.08096201,0.14767776,0.17510818,0.18053014,0.22527342,0.23179970,0.23432558,0.32411147,0.32589530,0.34615925,0.32575976,0.31977375,0.36931207,0.34838094,0.32681132,0.34356605,0.,0.,0.,0.,0.},
{0.07065979,0.10683010,0.14207214,0.20664968,0.23284327,0.23889126,0.27536511,0.30186900,0.30258394,0.40032339,0.35666162,0.36040299,0.35150190,0.40578304,0.,0.,0.,0.,0.,0.,0.},  
{0.08167300,0.12957732,0.14651426,0.18986216,0.25062284,0.23657198,0.40086905,0.39356091,0.33213115,0.38394962,0.35244783,0.36772301,0.37078185,0.,0.,0.,0.,0.,0.,0.,0.},
{0.11360277,0.11739167,0.14670139,0.24574498,0.26955662,0.27136714,0.24514191,0.33039206,0.31580363,0.39261412,0.34790003,0.37678554,0.,0.,0.,0.,0.,0.,0.,0.,0.},
{0.07917859,0.15988231,0.15330183,0.21939092,0.23837107,0.22853671,0.25077950,0.34409317,0.33106039,0.41484414,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.}};



for(k = 0;k<=11;k++){
for (j=0;j<nbins[k];j++){

h_fed_int[k]->SetBinContent(j+1,sect_arr[k][j]);
h_fed_int[k]->SetBinError(j+1,sect_arr_err[k][j]);
};
};




for (j=0;j<=11;j++){

c->cd(j+1);
c->cd(j+1)->SetBottomMargin(0.15);
c->cd(j+1)->SetLeftMargin(0.15);


h_fed_int[j]->SetMarkerStyle(20);
//h_fed_int[j]->SetMarkerSize(0.8);
h_fed_int[j]->SetMarkerColor(kBlue);
h_fed_int[j]->SetLineColor(kBlue);


qqq.str("");
qqq << "Q^{2} = "<<0.425 + 0.05*j <<" GeV^{2}";

h_fed_int[j]->SetTitle(qqq.str().c_str());
h_fed_int[j]->SetTitleSize(0.13);
h_fed_int[j]->GetYaxis()->SetLabelSize(0.05);
h_fed_int[j]->GetXaxis()->SetLabelSize(0.06);
h_fed_int[j]->GetXaxis()->SetTitle("W, GeV");
h_fed_int[j]->GetYaxis()->SetTitle("#sigma, #mub");
h_fed_int[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fed_int[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_fed_int[j]->GetXaxis()->SetTitleSize(0.06);
h_fed_int[j]->GetYaxis()->SetTitleSize(0.06);
h_fed_int[j]->SetMinimum(0.);
h_fed_int[j]->SetMaximum(35.);

h_fed_int[j]->Draw("pex0 e1");
};

//Skorodumina's cross sections.
TFile *MyFile1 = new TFile("out_fin_2021.root","READ");


MyFile1->cd();
gDirectory->GetObject("q2vsw_corr",q2vsw);

for (j=0;j<=11;j++){
qqq.str("");
qqq << "h_w_int_"<<j;
//gDirectory->GetObject(qqq.str().c_str(),h_skor_sect[j]);

h_skor_sect[j]=q2vsw->ProjectionX(qqq.str().c_str(),j+1,j+1);


cout << h_skor_sect[j]->GetNbinsX()<<"   b\n";
for (k=1;k<=h_skor_sect[j]->GetNbinsX();k++){
if ((j==0)&&(k<=12)) h_skor_sect[j]->SetBinError(k,0.);

if (k> nbins[j]) h_skor_sect[j]->SetBinContent(k,0.);
if (k> nbins[j]) h_skor_sect[j]->SetBinError(k,0.);
};


c->cd(j+1);
c->cd(j+1)->SetBottomMargin(0.15);
c->cd(j+1)->SetLeftMargin(0.15);

h_skor_sect[j]->SetMarkerStyle(20);
//h_skor_sect[j]->SetMarkerSize(0.8);
h_skor_sect[j]->SetMarkerColor(kBlack);
h_skor_sect[j]->SetLineColor(kBlack);

qqq.str("");
qqq << "Q^{2} = "<<0.425 + 0.05*j <<" GeV^{2}";

h_skor_sect[j]->SetTitle(qqq.str().c_str());
h_skor_sect[j]->SetTitleSize(0.13);
h_skor_sect[j]->GetYaxis()->SetLabelSize(0.05);
h_skor_sect[j]->GetXaxis()->SetLabelSize(0.06);
h_skor_sect[j]->GetXaxis()->SetTitle("W, GeV");
h_skor_sect[j]->GetYaxis()->SetTitle("#sigma, #mub");
//h_skor_sect[j]->GetXaxis()->SetNdivisions(9 + 100*4 + 10000*0);
//h_skor_sect[j]->GetYaxis()->SetNdivisions(9 + 100*4 + 10000*0);
h_skor_sect[j]->GetXaxis()->SetTitleSize(0.06);
h_skor_sect[j]->GetYaxis()->SetTitleSize(0.06);



h_skor_sect[j]->Draw("pex0 e1 same");

h_fract[j] = (TH1F*)h_skor_sect[j]->Clone();
h_fract[j]->Divide(h_fed_int[j]);

if (j == 0) pp1->cd();
if (j == 1) pp2->cd();
if (j == 2) pp3->cd();
if (j == 3) pp4->cd();
if (j == 4) pp5->cd();
if (j == 5) pp6->cd();
if (j == 6) pp7->cd();
if (j == 7) pp8->cd();
if (j == 8) pp9->cd();
if (j == 9) pp10->cd();
if (j == 10) pp11->cd();
if (j == 11) pp12->cd();

if ((j == 0) || (j == 4)) {
gPad->SetBottomMargin(small);
gPad->SetRightMargin(small);
gPad->SetLeftMargin(0.17);
gPad->SetTopMargin(small);

};
if (((j >0) && (j < 3)) ||((j >4) && (j < 7)))  {   
   gPad->SetBottomMargin(small);
   gPad->SetRightMargin(small);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(small);
};  

if ((j == 3) ||(j == 7))  {   
   gPad->SetBottomMargin(small);
//   gPad->SetRightMargin(small);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(small);
}; 

if (j == 8) {
gPad->SetBottomMargin(0.17);
gPad->SetRightMargin(small);
gPad->SetLeftMargin(0.17);
gPad->SetTopMargin(small);

};

if (j ==9)  {   
   gPad->SetBottomMargin(0.17);
   gPad->SetRightMargin(small);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(small);
};

if (j ==10) {   
   gPad->SetBottomMargin(0.17);
   gPad->SetRightMargin(0.02);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(small);
};  


if (j == 11) {
   gPad->SetBottomMargin(0.17);
//   gPad->SetRightMargin(small);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(small);
};




//c1->cd(j+1);
//c1->cd(j+1)->SetBottomMargin(0.15);
//c1->cd(j+1)->SetLeftMargin(0.15);

h_fract[j]->SetTitle(" ");

h_fract[j]->GetYaxis()->SetTitle("ratio");
h_fract[j]->GetYaxis()->SetRangeUser(0.25,1.15);

h_fract[j]->GetYaxis()->SetNdivisions(8 + 100*4 + 10000*0);

h_fract[j]->GetYaxis()->SetLabelSize(0.08);
h_fract[j]->GetXaxis()->SetLabelSize(0.075);

 if (j==8)h_fract[j]->GetYaxis()->SetLabelSize(0.07);
 
  if (j==8)h_fract[j]->GetXaxis()->SetLabelSize(0.073);
  if (j==9)h_fract[j]->GetXaxis()->SetLabelSize(0.08);

h_fract[j]->GetXaxis()->SetTitle("W (GeV)");
h_fract[j]->GetYaxis()->SetTitle("ratio"); 


h_fract[j]->GetXaxis()->SetTitleSize(0.07);
h_fract[j]->GetYaxis()->SetTitleSize(0.09);


 if (j==8)h_fract[j]->GetYaxis()->SetTitleSize(0.075);


 if (j==9)h_fract[j]->GetXaxis()->SetTitleSize(0.077);

h_fract[j]->GetXaxis()->SetTitleOffset(1.);
h_fract[j]->GetYaxis()->SetTitleOffset(0.9);

 if (j==8)h_fract[j]->GetYaxis()->SetTitleOffset(1.2); 


   if (j != 8) {
h_fract[j]->GetXaxis()->ChangeLabel(1,-1.,-1.,-1,-1,-1," ");
} else{
h_fract[j]->GetXaxis()->ChangeLabel(1,-1.,-1.,-1,-1,-1,"1.3");
};
h_fract[j]->GetYaxis()->ChangeLabel(8,-1.,-1.,-1,-1,-1," ");

h_fract[j]->GetXaxis()->SetRangeUser(1.2875,1.85);

h_fract[j]->Draw("pex0 e1");

TLine *line = new TLine(1.2875,1.,1.85,1.);
line->SetLineColor(12);
line->SetLineWidth(2);
//line->Draw("same");

TLine *line2 = new TLine(1.2875,0.75,1.85,0.75);
line2->SetLineColor(12);
line2->SetLineStyle(2);
line2->SetLineWidth(2);
line2->Draw("same");
h_fract[j]->Draw("pex0 e1 same");

//Polinomial fit.
 TF1 *g4;
 
if (j==0) g4 = new TF1("m4","pol4",1.6125, Wmax[j]);
if (j>0) g4 = new TF1("m4","pol4",1.3125, Wmax[j]);


p0 = (-339.01 -151.442 -254.115)/3.;
p1 = (872.085+395.987+647.427)/3.;
p2 = (-835.611 -385.176 -613.674)/3.;
p3 = (354.156+165.91+257.23)/3.;
p4 = (-56.0145 -26.6909 -40.2304)/3.;


cout << p0<< " "<<p1<<" "<<p2 <<" "<<p3<<" "<<p4 << " EEE \n";

//g4->SetParameter(0,607.005);
//g4->SetParLimits(0,-500,-100.);

g4->SetParameter(0,p0);
g4->SetParameter(1,p1);
g4->SetParameter(2,p2);
g4->SetParameter(3,p3);
g4->SetParameter(4,p4);


h_fract[j]->Fit(g4,"BR");


TPad*newpad2 = new TPad("newpad","a transparent pad",0.,0.,1.,1.);
 newpad2->SetFillStyle(4000);
 newpad2->Draw();
  newpad2->cd();
 TLatex tex1, tex2, tex3, tex4;  
tex1.SetTextSize(0.08);
if (j==8) tex1.SetTextSize(0.07);
if (j==9) tex1.SetTextSize(0.075);
if (j==10) tex1.SetTextSize(0.07);
if (j==11) tex1.SetTextSize(0.07);

if ((j==0)||(j==4)||(j==8)) tex1.DrawLatex(0.37,0.9,qqq.str().c_str());  
if ((j==1)||(j==5)||(j==9)) tex1.DrawLatex(0.25,0.9,qqq.str().c_str());  
if ((j==2)||(j==6)||(j==10)) tex1.DrawLatex(0.22,0.9,qqq.str().c_str()); 
if ((j==3)||(j==7)||(j==11)) tex1.DrawLatex(0.2,0.9,qqq.str().c_str()); 



//h_fract[j]->Fit("pol4","","",1.3,1.8);



//TLine *line3 = new TLine(1.3,1.5,1.825,1.5);
//line3->SetLineColor(kRed-9);
//line3->SetLineWidth(2);
//line3->Draw("same");
};
};
