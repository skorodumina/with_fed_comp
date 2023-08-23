//This script plots ratios of the angular distributions and fits them with polynomials.
//It uses six root files as an input. These root files are outputs of the scripts "fed_comp_theta.C" and "fed_comp_alpha.C".

void plot_angles(){
ostringstream qqq;
gStyle->SetOptStat(0);
gStyle->SetTitleSize(0.07,"t"); 


TCanvas *c2 = new TCanvas("c2","c2",0,0,700,466);
c2->Divide(3,2);

TH1F *h_theta_p, *h_theta_pip, *h_theta_pim;
TH1F *h_alpha_p, *h_alpha_pip, *h_alpha_pim;


TFile *MyFile1 = new TFile("out_theta_p.root","READ");
MyFile1->cd();
gDirectory->GetObject("h_fract_theta_p",h_theta_p);

TFile *MyFile2 = new TFile("out_theta_pim.root","READ");
MyFile2->cd();
gDirectory->GetObject("h_fract_theta_pim",h_theta_pim);

TFile *MyFile3 = new TFile("out_theta_pip.root","READ");
MyFile3->cd();
gDirectory->GetObject("h_fract_theta_pip",h_theta_pip);

TFile *MyFile4 = new TFile("out_alpha_p.root","READ");
MyFile4->cd();
gDirectory->GetObject("h_fract_alpha_p",h_alpha_p);


TFile *MyFile5 = new TFile("out_alpha_pim.root","READ");
MyFile5->cd();
gDirectory->GetObject("h_fract_alpha_pim",h_alpha_pim);

TFile *MyFile6 = new TFile("out_alpha_pip.root","READ");
MyFile6->cd();
gDirectory->GetObject("h_fract_alpha_pip",h_alpha_pip);


c2->cd(1);
c2->cd(1)->SetBottomMargin(0.2);
c2->cd(1)->SetTopMargin(0.13);
c2->cd(1)->SetLeftMargin(0.17);
c2->cd(1)->SetRightMargin(0.055);

h_theta_p->SetTitle("");
 h_theta_p->GetYaxis()->SetTitle("ratio");
 h_theta_p->GetXaxis()->SetTitle("#theta_{p'} (deg)");
 h_theta_p->GetXaxis()->SetTitleSize(0.08);
 h_theta_p->GetXaxis()->SetTitleOffset(1.1);
 h_theta_p->GetYaxis()->SetTitleSize(0.07);
 h_theta_p->GetYaxis()->SetTitleOffset(1.);
 h_theta_p->GetXaxis()->SetLabelSize(0.075);
// h_theta_p->GetXaxis()->SetNdivisions(5 +300);
 h_theta_p->GetYaxis()->SetLabelSize(0.07);
 h_theta_p->GetYaxis()->SetNdivisions(5);
 h_theta_p->GetXaxis()->SetNdivisions(-4 );
 
h_theta_p->GetYaxis()->SetRangeUser(0.5,1.05); 

h_theta_p->Draw("pex0 e1");

TLine *line2 = new TLine(0.,0.75,180,0.75);
line2->SetLineColor(12);
line2->SetLineStyle(2);
line2->SetLineWidth(2);
line2->Draw("same");

h_theta_p->Draw("pex0 e1 same");
h_theta_p->Fit("pol4","","",0,180);

c2->cd(2);
c2->cd(2)->SetBottomMargin(0.2);
c2->cd(2)->SetTopMargin(0.13);
c2->cd(2)->SetLeftMargin(0.17);
c2->cd(2)->SetRightMargin(0.055);

h_theta_pim->SetTitle("");
 h_theta_pim->GetYaxis()->SetTitle("ratio");
 h_theta_pim->GetXaxis()->SetTitle("#theta_{#pi^{-}} (deg)");
 h_theta_pim->GetXaxis()->SetTitleSize(0.08);
 h_theta_pim->GetXaxis()->SetTitleOffset(1.1);
 h_theta_pim->GetYaxis()->SetTitleSize(0.07);
 h_theta_pim->GetYaxis()->SetTitleOffset(1.);
 h_theta_pim->GetXaxis()->SetLabelSize(0.075);
// h_theta_pim->GetXaxis()->SetNdivisions(5 +300);
 h_theta_pim->GetYaxis()->SetLabelSize(0.07);
 h_theta_pim->GetYaxis()->SetNdivisions(5);
 h_theta_pim->GetXaxis()->SetNdivisions(-4 );
 
 
h_theta_pim->GetYaxis()->SetRangeUser(0.5,1.05); 
h_theta_pim->Draw("pex0 e1");

TLine *line22 = new TLine(0.,0.75,180,0.75);
line22->SetLineColor(12);
line22->SetLineStyle(2);
line22->SetLineWidth(2);
line22->Draw("same");

h_theta_pim->Draw("pex0 e1 same");

/*Double_t par[11];
TF1 *g1 = new TF1("m1","pol5",0.,90.);
TF1 *g2 = new TF1("m2","pol4",90., 180);
TF1 *total = new TF1("mstotal","pol5(0)+pol4(5)",0.0,180.);
h_theta_pim->Fit(g1,"R+");
h_theta_pim->Fit(g2,"R+");
g1->GetParameters(&par[0]);
g2->GetParameters(&par[5]);
total->SetParameters(par);
//h_theta_pim->Fit(total,"R+");

//h_theta_pim->Fit("pol5","","",0,90);*/

h_theta_pim->Fit("pol4","","",00,180);

c2->cd(3);
c2->cd(3)->SetBottomMargin(0.2);
c2->cd(3)->SetTopMargin(0.13);
c2->cd(3)->SetLeftMargin(0.17);
c2->cd(3)->SetRightMargin(0.055);

h_theta_pip->SetTitle("");
 h_theta_pip->GetYaxis()->SetTitle("ratio");
 h_theta_pip->GetXaxis()->SetTitle("#theta_{#pi^{+}} (deg)");
 h_theta_pip->GetXaxis()->SetTitleSize(0.08);
 h_theta_pip->GetXaxis()->SetTitleOffset(1.1);
 h_theta_pip->GetYaxis()->SetTitleSize(0.07);
 h_theta_pip->GetYaxis()->SetTitleOffset(1.);
 h_theta_pip->GetXaxis()->SetLabelSize(0.075);
// h_theta_pip->GetXaxis()->SetNdivisions(5 +300);
 h_theta_pip->GetYaxis()->SetLabelSize(0.07);
 h_theta_pip->GetYaxis()->SetNdivisions(5); 
 
 h_theta_pip->GetXaxis()->SetNdivisions(-4 );
 
h_theta_pip->GetYaxis()->SetRangeUser(0.5,1.05); 
h_theta_pip->Draw("pex0 e1");

TLine *line23 = new TLine(0.,0.75,180,0.75);
line23->SetLineColor(12);
line23->SetLineStyle(2);
line23->SetLineWidth(2);
line23->Draw("same");

h_theta_pip->Draw("pex0 e1 same");
h_theta_pip->Fit("pol4","","",0,180);

c2->cd(4);
c2->cd(4)->SetBottomMargin(0.2);
c2->cd(4)->SetTopMargin(0.13);
c2->cd(4)->SetLeftMargin(0.17);
c2->cd(4)->SetRightMargin(0.055);

h_alpha_p->SetTitle("");
 h_alpha_p->GetYaxis()->SetTitle("ratio");
 h_alpha_p->GetXaxis()->SetTitle("#alpha_{p'} (deg)");
 h_alpha_p->GetXaxis()->SetTitleSize(0.08);
 h_alpha_p->GetXaxis()->SetTitleOffset(1.1);
 h_alpha_p->GetYaxis()->SetTitleSize(0.07);
 h_alpha_p->GetYaxis()->SetTitleOffset(1.);
 h_alpha_p->GetXaxis()->SetLabelSize(0.075);
// h_alpha_p->GetXaxis()->SetNdivisions(5 +300);
 h_alpha_p->GetYaxis()->SetLabelSize(0.07);
 h_alpha_p->GetYaxis()->SetNdivisions(5);
h_alpha_p->GetYaxis()->SetRangeUser(0.5,1.05); 

h_alpha_p->GetXaxis()->SetNdivisions(-4 );
h_alpha_p->Draw("pex0 e1");

TLine *line24 = new TLine(0.,0.75,360,0.75);
line24->SetLineColor(12);
line24->SetLineStyle(2);
line24->SetLineWidth(2);
line24->Draw("same");

h_alpha_p->Draw("pex0 e1 same");
h_alpha_p->Fit("pol2","","",0,360);

c2->cd(5);
c2->cd(5)->SetBottomMargin(0.2);
c2->cd(5)->SetTopMargin(0.13);
c2->cd(5)->SetLeftMargin(0.17);
c2->cd(5)->SetRightMargin(0.055);

h_alpha_pim->SetTitle("");
 h_alpha_pim->GetYaxis()->SetTitle("ratio");
 h_alpha_pim->GetXaxis()->SetTitle("#alpha_{#pi^{-}} (deg)");
 h_alpha_pim->GetXaxis()->SetTitleSize(0.08);
 h_alpha_pim->GetXaxis()->SetTitleOffset(1.1);
 h_alpha_pim->GetYaxis()->SetTitleSize(0.07);
 h_alpha_pim->GetYaxis()->SetTitleOffset(1.);
 h_alpha_pim->GetXaxis()->SetLabelSize(0.075);
// h_alpha_pim->GetXaxis()->SetNdivisions(5 +300);
 h_alpha_pim->GetYaxis()->SetLabelSize(0.07);
 h_alpha_pim->GetYaxis()->SetNdivisions(5);
h_alpha_pim->GetYaxis()->SetRangeUser(0.5,1.05);
h_alpha_pim->GetXaxis()->SetNdivisions(-4 );
h_alpha_pim->Draw("pex0 e1");

TLine *line25 = new TLine(0.,0.75,360,0.75);
line25->SetLineColor(12);
line25->SetLineStyle(2);
line25->SetLineWidth(2);
line25->Draw("same");

h_alpha_pim->Draw("pex0 e1 same");
h_alpha_pim->Fit("pol4","","",0,360);

c2->cd(6);
c2->cd(6)->SetBottomMargin(0.2);
c2->cd(6)->SetTopMargin(0.13);
c2->cd(6)->SetLeftMargin(0.17);
c2->cd(6)->SetRightMargin(0.055);

h_alpha_pip->SetTitle("");
 h_alpha_pip->GetYaxis()->SetTitle("ratio");
 h_alpha_pip->GetXaxis()->SetTitle("#alpha_{#pi^{+}} (deg)");
 h_alpha_pip->GetXaxis()->SetTitleSize(0.08);
 h_alpha_pip->GetXaxis()->SetTitleOffset(1.1);
 h_alpha_pip->GetYaxis()->SetTitleSize(0.07);
 h_alpha_pip->GetYaxis()->SetTitleOffset(1.);
 h_alpha_pip->GetXaxis()->SetLabelSize(0.075);
// h_alpha_pip->GetXaxis()->SetNdivisions(5 +300);
 h_alpha_pip->GetYaxis()->SetLabelSize(0.07);
 h_alpha_pip->GetYaxis()->SetNdivisions(5);
h_alpha_pip->GetYaxis()->SetRangeUser(0.5,1.05);
h_alpha_pip->GetXaxis()->SetNdivisions(-4 );
h_alpha_pip->Draw("pex0 e1");

TLine *line26 = new TLine(0.,0.75,360,0.75);
line26->SetLineColor(12);
line26->SetLineStyle(2);
line26->SetLineWidth(2);
line26->Draw("same");

h_alpha_pip->Draw("pex0 e1 same");
h_alpha_pip->Fit("pol4","","",0,360);

};
