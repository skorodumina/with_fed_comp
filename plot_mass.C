//This script plots ratios of the invariant mass distributions and fits them with polynomials.
//It uses three root files as an input. These root files are outputs of the script "fed_comp_inv.C".

void plot_mass(){
ostringstream qqq;
gStyle->SetOptStat(0);
gStyle->SetTitleSize(0.07,"t"); 
gStyle->SetTitleY(0.94);
gStyle->SetTitleAlign(33);
gStyle->SetTitleX(.84);

TCanvas *c2 = new TCanvas("c2","c2",0,0,1000,1000);
c2->Divide(4,3);


gStyle->SetPadBorderMode(0);
   gStyle->SetFrameBorderMode(0);
   Float_t small = 1e-5;
//   c1.Divide(2,2,small,small);

//c->Divide(4,3,small,small);
c2->cd();
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



TH1F *h_mass_pip_p1, *h_mass_pip_p2, *h_mass_pip_p3, *h_mass_pip_p4;
TH1F *h_mass_pip_pim1, *h_mass_pip_pim2, *h_mass_pip_pim3, *h_mass_pip_pim4;
TH1F *h_mass_pim_p1, *h_mass_pim_p2, *h_mass_pim_p3, *h_mass_pim_p4;


TFile *MyFile1 = new TFile("out_inv_mass_pip_pr.root","READ");
MyFile1->cd();
gDirectory->GetObject("h_fract_sum7",h_mass_pip_p1);
gDirectory->GetObject("h_fract_sum11",h_mass_pip_p2);
gDirectory->GetObject("h_fract_sum15",h_mass_pip_p3);
gDirectory->GetObject("h_fract_sum19",h_mass_pip_p4);


TFile *MyFile2 = new TFile("out_inv_mass_pip_pim.root","READ");
MyFile2->cd();
gDirectory->GetObject("h_fract_sum7",h_mass_pip_pim1);
gDirectory->GetObject("h_fract_sum11",h_mass_pip_pim2);
gDirectory->GetObject("h_fract_sum15",h_mass_pip_pim3);
gDirectory->GetObject("h_fract_sum19",h_mass_pip_pim4);


TFile *MyFile3 = new TFile("out_inv_mass_pim_pr.root","READ");
MyFile3->cd();
gDirectory->GetObject("h_fract_sum7",h_mass_pim_p1);
gDirectory->GetObject("h_fract_sum11",h_mass_pim_p2);
gDirectory->GetObject("h_fract_sum15",h_mass_pim_p3);
gDirectory->GetObject("h_fract_sum19",h_mass_pim_p4);



//------------------------

c2->cd(1);
c2->cd(1)->SetBottomMargin(0.2);
c2->cd(1)->SetTopMargin(0.13);
c2->cd(1)->SetLeftMargin(0.23);
c2->cd(1)->SetRightMargin(0.01);

h_mass_pip_p1->SetTitle(" ");
 h_mass_pip_p1->GetYaxis()->SetTitle("ratio");
 h_mass_pip_p1->GetXaxis()->SetTitle("M_{#pi^{+}p'} (GeV)");
 h_mass_pip_p1->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_p1->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_p1->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_p1->GetYaxis()->SetTitleOffset(0.9);
 h_mass_pip_p1->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_p1->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pip_p1->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_p1->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_p1->GetYaxis()->SetRangeUser(0.2,1.2); 

pp1->cd();
gPad->SetBottomMargin(0.2);
gPad->SetRightMargin(small);
gPad->SetLeftMargin(0.13);
gPad->SetTopMargin(0.02);

h_mass_pip_p1->Draw("pex0 e1");


TLine *line2 = new TLine(h_mass_pip_p1->GetBinLowEdge(1),0.75,h_mass_pip_p1->GetBinLowEdge(11)+2*h_mass_pip_p1->GetBinWidth(1),0.75);
line2->SetLineColor(12);
line2->SetLineStyle(2);
line2->SetLineWidth(2);
line2->Draw("same");

h_mass_pip_p1->Draw("pex0 e1 same");
h_mass_pip_p1->Fit("pol4","","",h_mass_pip_p1->GetBinLowEdge(1),h_mass_pip_p1->GetBinLowEdge(11)+h_mass_pip_p1->GetBinWidth(1));

c2->cd(2);
c2->cd(2)->SetBottomMargin(0.2);
c2->cd(2)->SetTopMargin(0.13);
c2->cd(2)->SetLeftMargin(0.23);
c2->cd(2)->SetRightMargin(0.01);

h_mass_pip_p2->SetTitle(" ");
 h_mass_pip_p2->GetYaxis()->SetTitle("ratio");
 h_mass_pip_p2->GetXaxis()->SetTitle("M_{#pi^{+}p'} (GeV)");
 h_mass_pip_p2->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_p2->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_p2->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_p2->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pip_p2->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_p2->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pip_p2->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_p2->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_p2->GetYaxis()->SetRangeUser(0.2,1.2); 

 pp2->cd();
 gPad->SetBottomMargin(0.2);
//gPad->SetRightMargin(small);
gPad->SetLeftMargin(small);
gPad->SetTopMargin(0.02);
 
h_mass_pip_p2->Draw("pex0 e1");


TLine *line22 = new TLine(h_mass_pip_p2->GetBinLowEdge(1),0.75,h_mass_pip_p2->GetBinLowEdge(11)+2*h_mass_pip_p2->GetBinWidth(1),0.75);
line22->SetLineColor(12);
line22->SetLineStyle(2);
line22->SetLineWidth(2);
line22->Draw("same");

h_mass_pip_p2->Draw("pex0 e1 same");
h_mass_pip_p2->Fit("pol4","","",h_mass_pip_p2->GetBinLowEdge(1),h_mass_pip_p2->GetBinLowEdge(11)+h_mass_pip_p2->GetBinWidth(1));

c2->cd(3);
c2->cd(3)->SetBottomMargin(0.2);
c2->cd(3)->SetTopMargin(0.13);
c2->cd(3)->SetLeftMargin(0.23);
c2->cd(3)->SetRightMargin(0.01);

h_mass_pip_p3->SetTitle(" ");
 h_mass_pip_p3->GetYaxis()->SetTitle("ratio");
 h_mass_pip_p3->GetXaxis()->SetTitle("M_{#pi^{+}p'} (GeV)");
 h_mass_pip_p3->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_p3->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_p3->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_p3->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pip_p3->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_p3->GetXaxis()->SetNdivisions(7 +300);
 h_mass_pip_p3->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_p3->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_p3->GetYaxis()->SetRangeUser(0.2,1.2); 
 pp3->cd();
gPad->SetBottomMargin(0.2);
gPad->SetRightMargin(0.02);
gPad->SetLeftMargin(0.0);
gPad->SetTopMargin(0.02);

h_mass_pip_p3->Draw("pex0 e1");


TLine *line23 = new TLine(h_mass_pip_p3->GetBinLowEdge(1),0.75,h_mass_pip_p3->GetBinLowEdge(11)+2*h_mass_pip_p3->GetBinWidth(1),0.75);
line23->SetLineColor(12);
line23->SetLineStyle(2);
line23->SetLineWidth(2);
line23->Draw("same");

h_mass_pip_p3->Draw("pex0 e1 same");
h_mass_pip_p3->Fit("pol4","","",h_mass_pip_p3->GetBinLowEdge(1),h_mass_pip_p3->GetBinLowEdge(11)+h_mass_pip_p3->GetBinWidth(1));


c2->cd(4);
c2->cd(4)->SetBottomMargin(0.2);
c2->cd(4)->SetTopMargin(0.13);
c2->cd(4)->SetLeftMargin(0.23);
c2->cd(4)->SetRightMargin(0.01);

h_mass_pip_p4->SetTitle(" ");
 h_mass_pip_p4->GetYaxis()->SetTitle("ratio");
 h_mass_pip_p4->GetXaxis()->SetTitle("M_{#pi^{+}p'} (GeV)");
 h_mass_pip_p4->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_p4->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_p4->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_p4->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pip_p4->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_p4->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pip_p4->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_p4->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_p4->GetYaxis()->SetRangeUser(0.2,1.2); 

pp4->cd();
gPad->SetBottomMargin(0.2);
gPad->SetRightMargin(0.04);
//gPad->SetLeftMargin(small);
gPad->SetTopMargin(0.02);

h_mass_pip_p4->Draw("pex0 e1");

TLine *line24 = new TLine(h_mass_pip_p4->GetBinLowEdge(1),0.75,h_mass_pip_p4->GetBinLowEdge(11)+2*h_mass_pip_p4->GetBinWidth(1),0.75);
line24->SetLineColor(12);
line24->SetLineStyle(2);
line24->SetLineWidth(2);
line24->Draw("same");

h_mass_pip_p4->Draw("pex0 e1 same");
h_mass_pip_p4->Fit("pol4","","",h_mass_pip_p4->GetBinLowEdge(1),h_mass_pip_p4->GetBinLowEdge(11)+h_mass_pip_p4->GetBinWidth(1));


//------------------------

c2->cd(5);
c2->cd(5)->SetBottomMargin(0.2);
c2->cd(5)->SetTopMargin(0.13);
c2->cd(5)->SetLeftMargin(0.23);
c2->cd(5)->SetRightMargin(0.01);

h_mass_pip_pim1->SetTitle(" ");
 h_mass_pip_pim1->GetYaxis()->SetTitle("ratio");
 h_mass_pip_pim1->GetXaxis()->SetTitle("M_{#pi^{+}#pi^{-}} (GeV)");
 h_mass_pip_pim1->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_pim1->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_pim1->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_pim1->GetYaxis()->SetTitleOffset(0.9);
 h_mass_pip_pim1->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_pim1->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pip_pim1->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_pim1->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_pim1->GetYaxis()->SetRangeUser(0.2,1.2); 

pp5->cd();

gPad->SetBottomMargin(0.18);
//gPad->SetRightMargin(small);
gPad->SetLeftMargin(0.13);
gPad->SetTopMargin(0.02);

h_mass_pip_pim1->Draw("pex0 e1");

TLine *line25 = new TLine(h_mass_pip_pim1->GetBinLowEdge(1),0.75,h_mass_pip_pim1->GetBinLowEdge(11)+2*h_mass_pip_pim1->GetBinWidth(1),0.75);
line25->SetLineColor(12);
line25->SetLineStyle(2);
line25->SetLineWidth(2);
line25->Draw("same");

h_mass_pip_pim1->Draw("pex0 e1 same");
h_mass_pip_pim1->Fit("pol4","","",h_mass_pip_pim1->GetBinLowEdge(1),h_mass_pip_pim1->GetBinLowEdge(11)+h_mass_pip_pim1->GetBinWidth(1));


c2->cd(6);
c2->cd(6)->SetBottomMargin(0.2);
c2->cd(6)->SetTopMargin(0.13);
c2->cd(6)->SetLeftMargin(0.23);
c2->cd(6)->SetRightMargin(0.01);

h_mass_pip_pim2->SetTitle(" ");
 h_mass_pip_pim2->GetYaxis()->SetTitle("ratio");
 h_mass_pip_pim2->GetXaxis()->SetTitle("M_{#pi^{+}#pi^{-}} (GeV)");
 h_mass_pip_pim2->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_pim2->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_pim2->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_pim2->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pip_pim2->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_pim2->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pip_pim2->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_pim2->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_pim2->GetYaxis()->SetRangeUser(0.2,1.2); 

pp6->cd();
   gPad->SetBottomMargin(0.18);
   gPad->SetRightMargin(small);
//   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(0.02);
   
h_mass_pip_pim2->Draw("pex0 e1");

TLine *line26 = new TLine(h_mass_pip_pim2->GetBinLowEdge(1),0.75,h_mass_pip_pim2->GetBinLowEdge(11)+2*h_mass_pip_pim2->GetBinWidth(1),0.75);
line26->SetLineColor(12);
line26->SetLineStyle(2);
line26->SetLineWidth(2);
line26->Draw("same");

h_mass_pip_pim2->Draw("pex0 e1 same");
h_mass_pip_pim2->Fit("pol4","","",h_mass_pip_pim2->GetBinLowEdge(1),h_mass_pip_pim2->GetBinLowEdge(11)+h_mass_pip_pim2->GetBinWidth(1));


c2->cd(7);
c2->cd(7)->SetBottomMargin(0.2);
c2->cd(7)->SetTopMargin(0.13);
c2->cd(7)->SetLeftMargin(0.23);
c2->cd(7)->SetRightMargin(0.01);

h_mass_pip_pim3->SetTitle(" ");
 h_mass_pip_pim3->GetYaxis()->SetTitle("ratio");
 h_mass_pip_pim3->GetXaxis()->SetTitle("M_{#pi^{+}#pi^{-}} (GeV)");
 h_mass_pip_pim3->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_pim3->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_pim3->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_pim3->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pip_pim3->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_pim3->GetXaxis()->SetNdivisions(7 +300);
 h_mass_pip_pim3->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_pim3->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_pim3->GetYaxis()->SetRangeUser(0.2,1.2); 

 pp7->cd();
   gPad->SetBottomMargin(0.18);
   gPad->SetRightMargin(0.02);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(0.02);
   
h_mass_pip_pim3->Draw("pex0 e1");

TLine *line27 = new TLine(h_mass_pip_pim3->GetBinLowEdge(1),0.75,h_mass_pip_pim3->GetBinLowEdge(11)+2*h_mass_pip_pim3->GetBinWidth(1),0.75);
line27->SetLineColor(12);
line27->SetLineStyle(2);
line27->SetLineWidth(2);
line27->Draw("same");

h_mass_pip_pim3->Draw("pex0 e1 same");
h_mass_pip_pim3->Fit("pol4","","",h_mass_pip_pim3->GetBinLowEdge(1),h_mass_pip_pim3->GetBinLowEdge(11)+h_mass_pip_pim3->GetBinWidth(1));

c2->cd(8);
c2->cd(8)->SetBottomMargin(0.2);
c2->cd(8)->SetTopMargin(0.13);
c2->cd(8)->SetLeftMargin(0.23);
c2->cd(8)->SetRightMargin(0.01);

h_mass_pip_pim4->SetTitle(" ");
 h_mass_pip_pim4->GetYaxis()->SetTitle("ratio");
 h_mass_pip_pim4->GetXaxis()->SetTitle("M_{#pi^{+}#pi^{-}} (GeV)");
 h_mass_pip_pim4->GetXaxis()->SetTitleSize(0.08);
 h_mass_pip_pim4->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pip_pim4->GetYaxis()->SetTitleSize(0.07);
 h_mass_pip_pim4->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pip_pim4->GetXaxis()->SetLabelSize(0.075);
 h_mass_pip_pim4->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pip_pim4->GetYaxis()->SetLabelSize(0.07);
 h_mass_pip_pim4->GetYaxis()->SetNdivisions(7);
 
h_mass_pip_pim4->GetYaxis()->SetRangeUser(0.2,1.2); 

 pp8->cd();
gPad->SetBottomMargin(0.18);
gPad->SetRightMargin(0.05);
//gPad->SetLeftMargin(small);
gPad->SetTopMargin(0.02);

h_mass_pip_pim4->Draw("pex0 e1");

TLine *line28 = new TLine(h_mass_pip_pim4->GetBinLowEdge(1),0.75,h_mass_pip_pim4->GetBinLowEdge(11)+2*h_mass_pip_pim4->GetBinWidth(1),0.75);
line28->SetLineColor(12);
line28->SetLineStyle(2);
line28->SetLineWidth(2);
line28->Draw("same");

h_mass_pip_pim4->Draw("pex0 e1 same");
h_mass_pip_pim4->Fit("pol4","","",h_mass_pip_pim4->GetBinLowEdge(1),h_mass_pip_pim4->GetBinLowEdge(11)+h_mass_pip_pim4->GetBinWidth(1));

//------------------------

c2->cd(9);
c2->cd(9)->SetBottomMargin(0.2);
c2->cd(9)->SetTopMargin(0.13);
c2->cd(9)->SetLeftMargin(0.23);
c2->cd(9)->SetRightMargin(0.01);

h_mass_pim_p1->SetTitle(" ");
 h_mass_pim_p1->GetYaxis()->SetTitle("ratio");
 h_mass_pim_p1->GetXaxis()->SetTitle("M_{#pi^{-}p'} (GeV)");
 h_mass_pim_p1->GetXaxis()->SetTitleSize(0.0675);
 h_mass_pim_p1->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pim_p1->GetYaxis()->SetTitleSize(0.06);
 h_mass_pim_p1->GetYaxis()->SetTitleOffset(1.);
 h_mass_pim_p1->GetXaxis()->SetLabelSize(0.0675);
 h_mass_pim_p1->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pim_p1->GetYaxis()->SetLabelSize(0.06);
 h_mass_pim_p1->GetYaxis()->SetNdivisions(7);
 
h_mass_pim_p1->GetYaxis()->SetRangeUser(0.2,1.2); 


 pp9->cd();
 gPad->SetBottomMargin(0.25);
   gPad->SetRightMargin(small);
   gPad->SetLeftMargin(0.13);
   gPad->SetTopMargin(0.07);

 
h_mass_pim_p1->Draw("pex0 e1");

TLine *line29 = new TLine(h_mass_pim_p1->GetBinLowEdge(1),0.75,h_mass_pim_p1->GetBinLowEdge(11)+2*h_mass_pim_p1->GetBinWidth(1),0.75);
line29->SetLineColor(12);
line29->SetLineStyle(2);
line29->SetLineWidth(2);
line29->Draw("same");

h_mass_pim_p1->Draw("pex0 e1 same");
h_mass_pim_p1->Fit("pol4","","",h_mass_pim_p1->GetBinLowEdge(1),h_mass_pim_p1->GetBinLowEdge(11)+h_mass_pim_p1->GetBinWidth(1));

c2->cd(10);
c2->cd(10)->SetBottomMargin(0.2);
c2->cd(10)->SetTopMargin(0.13);
c2->cd(10)->SetLeftMargin(0.23);
c2->cd(10)->SetRightMargin(0.01);

h_mass_pim_p2->SetTitle(" ");
 h_mass_pim_p2->GetYaxis()->SetTitle("ratio");
 h_mass_pim_p2->GetXaxis()->SetTitle("M_{#pi^{-}p'} (GeV)");
 h_mass_pim_p2->GetXaxis()->SetTitleSize(0.0675);
 h_mass_pim_p2->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pim_p2->GetYaxis()->SetTitleSize(0.07);
 h_mass_pim_p2->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pim_p2->GetXaxis()->SetLabelSize(0.0675);
 h_mass_pim_p2->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pim_p2->GetYaxis()->SetLabelSize(0.07);
 h_mass_pim_p2->GetYaxis()->SetNdivisions(7);
 
h_mass_pim_p2->GetYaxis()->SetRangeUser(0.2,1.2); 
pp10->cd();
  gPad->SetBottomMargin(0.25);
//   gPad->SetRightMargin(small);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(0.07);

h_mass_pim_p2->Draw("pex0 e1");

TLine *line210 = new TLine(h_mass_pim_p2->GetBinLowEdge(1),0.75,h_mass_pim_p2->GetBinLowEdge(11)+2*h_mass_pim_p2->GetBinWidth(1),0.75);
line210->SetLineColor(12);
line210->SetLineStyle(2);
line210->SetLineWidth(2);
line210->Draw("same");

h_mass_pim_p2->Draw("pex0 e1 same");
h_mass_pim_p2->Fit("pol4","","",h_mass_pim_p2->GetBinLowEdge(1),h_mass_pim_p2->GetBinLowEdge(11)+h_mass_pim_p2->GetBinWidth(1));

c2->cd(11);
c2->cd(11)->SetBottomMargin(0.2);
c2->cd(11)->SetTopMargin(0.13);
c2->cd(11)->SetLeftMargin(0.23);
c2->cd(11)->SetRightMargin(0.01);

h_mass_pim_p3->SetTitle(" ");
 h_mass_pim_p3->GetYaxis()->SetTitle("ratio");
 h_mass_pim_p3->GetXaxis()->SetTitle("M_{#pi^{-}p'} (GeV)");
 h_mass_pim_p3->GetXaxis()->SetTitleSize(0.0675);
 h_mass_pim_p3->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pim_p3->GetYaxis()->SetTitleSize(0.07);
 h_mass_pim_p3->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pim_p3->GetXaxis()->SetLabelSize(0.0675);
 h_mass_pim_p3->GetXaxis()->SetNdivisions(7 +300);
 h_mass_pim_p3->GetYaxis()->SetLabelSize(0.07);
 h_mass_pim_p3->GetYaxis()->SetNdivisions(7);
 
h_mass_pim_p3->GetYaxis()->SetRangeUser(0.2,1.2); 


 pp11->cd();
   gPad->SetBottomMargin(0.25);
   gPad->SetRightMargin(0.02);
   gPad->SetLeftMargin(small);
   gPad->SetTopMargin(0.07);


h_mass_pim_p3->Draw("pex0 e1");

TLine *line211 = new TLine(h_mass_pim_p3->GetBinLowEdge(1),0.75,h_mass_pim_p3->GetBinLowEdge(11)+2*h_mass_pim_p3->GetBinWidth(1),0.75);
line211->SetLineColor(12);
line211->SetLineStyle(2);
line211->SetLineWidth(2);
line211->Draw("same");

h_mass_pim_p3->Draw("pex0 e1 same");
h_mass_pim_p3->Fit("pol4","","",h_mass_pim_p3->GetBinLowEdge(1),h_mass_pim_p3->GetBinLowEdge(11)+h_mass_pim_p3->GetBinWidth(1));


c2->cd(12);
c2->cd(12)->SetBottomMargin(0.2);
c2->cd(12)->SetTopMargin(0.13);
c2->cd(12)->SetLeftMargin(0.23);
c2->cd(12)->SetRightMargin(0.01);

h_mass_pim_p4->SetTitle(" ");
 h_mass_pim_p4->GetYaxis()->SetTitle("ratio");
 h_mass_pim_p4->GetXaxis()->SetTitle("M_{#pi^{-}p'} (GeV)");
 h_mass_pim_p4->GetXaxis()->SetTitleSize(0.0675);
 h_mass_pim_p4->GetXaxis()->SetTitleOffset(1.1);
 h_mass_pim_p4->GetYaxis()->SetTitleSize(0.07);
 h_mass_pim_p4->GetYaxis()->SetTitleOffset(1.3);
 h_mass_pim_p4->GetXaxis()->SetLabelSize(0.0675);
 h_mass_pim_p4->GetXaxis()->SetNdivisions(5 +300);
 h_mass_pim_p4->GetYaxis()->SetLabelSize(0.07);
 h_mass_pim_p4->GetYaxis()->SetNdivisions(7);
 
h_mass_pim_p4->GetYaxis()->SetRangeUser(0.2,1.2); 

 pp12->cd();
 gPad->SetBottomMargin(0.25);
   gPad->SetRightMargin(0.05);
 //  gPad->SetLeftMargin(small);
   gPad->SetTopMargin(0.07);
   
h_mass_pim_p4->Draw("pex0 e1");

TLine *line212 = new TLine(h_mass_pim_p4->GetBinLowEdge(1),0.75,h_mass_pim_p4->GetBinLowEdge(11)+2*h_mass_pim_p4->GetBinWidth(1),0.75);
line212->SetLineColor(12);
line212->SetLineStyle(2);
line212->SetLineWidth(2);
line212->Draw("same");

h_mass_pim_p4->Draw("pex0 e1 same");
h_mass_pim_p4->Fit("pol4","","",h_mass_pim_p4->GetBinLowEdge(1),h_mass_pim_p4->GetBinLowEdge(11)+h_mass_pim_p4->GetBinWidth(1));



c2->cd();
TPad *newpad2 = new TPad("newpad","a transparent pad",0.,0.,1.,1.);
 newpad2->SetFillStyle(4000);
 newpad2->Draw();
  newpad2->cd();
 TLatex tex1, tex2, tex3, tex4;  

tex1.SetTextSize(0.023);
tex1.DrawLatex(0.13,0.955,"#bf{W = 1.4625 GeV}");  

tex2.SetTextSize(0.023);
tex2.DrawLatex(0.35,0.955,"#bf{W = 1.5625 GeV}"); 


tex3.SetTextSize(0.023);
tex3.DrawLatex(0.58,0.955,"#bf{W = 1.6625 GeV}"); 

tex4.SetTextSize(0.023);
tex4.DrawLatex(0.81,0.955,"#bf{W = 1.7625 GeV}");

};
