#include <QtGui>
#include "ProcessorWindow.h"

ProcessorWindow::ProcessorWindow()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Variable instantiations
   currentlyCheckedBox = -1;
   currentAmount = 0;
   budgetAmount = 0;
   
   // Ensure a starting empty vector
   layouts.clear();
   boxOptions.clear();
   expandableButtons.clear();
   itemPriceLabels.clear();
   itemPrices.clear();
   productImages.clear();
   pixMaps.clear();
   specWindows.clear();
   
   // Load our assets
   loadAssets();
   
   // Instantiate all of our vectors and populate them
   for (int i = 0; i < 6; ++i)
   {
      boxOptions.push_back(new QCheckBox());
      expandableButtons.push_back(new QPushButton());
      itemPriceLabels.push_back(new QLabel());
      productImages.push_back(new QLabel());
      specWindows.push_back(new SpecificationWindow());
      
      productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 10, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      expandableButtons[i]->setText("View Now");
      expandableButtons[i]->setStyleSheet("text-align:right; border:0px;");
      boxOptions[i]->setMinimumWidth(200);
   }
   
   // Load specs
   loadSpecs();
   
   // Make our layouts. Odd layouts not initially visible since widgets hidden
   for (int i = 0; i < 6; ++i)
   {
      layouts.push_back(new QHBoxLayout());
      layouts[i]->addWidget(productImages[i]);
      layouts[i]->addWidget(boxOptions[i]);
      layouts[i]->addWidget(itemPriceLabels[i]);
      layouts[i]->addWidget(expandableButtons[i]);
         
      mainLayout->addLayout(layouts[i]);
   }
   
   /// TODO : Double the amount of layouts and add inner versions for specifications (Maybe reviews)?
   
   // Set our values
   itemPriceLabels[0]->setText("$259.99");
   itemPrices.push_back(259.99);
   itemPriceLabels[1]->setText("$159.99");
   itemPrices.push_back(159.99);
   itemPriceLabels[2]->setText("$109.99");
   itemPrices.push_back(109.99);
   itemPriceLabels[3]->setText("$499.99");
   itemPrices.push_back(499.99);
   itemPriceLabels[4]->setText("$339.99");
   itemPrices.push_back(339.99);
   itemPriceLabels[5]->setText("$179.99");
   itemPrices.push_back(179.99);
   
   boxOptions[0]->setText("AMD FX-8350");
   boxOptions[1]->setText("AMD FX-6300");
   boxOptions[2]->setText("AMD Athlon X4");
   boxOptions[3]->setText("Intel Core i7-4790K");
   boxOptions[4]->setText("Intel Core i5-4690K");
   boxOptions[5]->setText("Intel Core i3-6100");
   
   this->setLayout(mainLayout);
   
   // Connect our check boxes
   connect(boxOptions[0], SIGNAL(stateChanged(int)), this, SLOT(updateBoxOne(int)));
   connect(boxOptions[1], SIGNAL(stateChanged(int)), this, SLOT(updateBoxTwo(int)));
   connect(boxOptions[2], SIGNAL(stateChanged(int)), this, SLOT(updateBoxThree(int)));
   connect(boxOptions[3], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFour(int)));
   connect(boxOptions[4], SIGNAL(stateChanged(int)), this, SLOT(updateBoxFive(int)));
   connect(boxOptions[5], SIGNAL(stateChanged(int)), this, SLOT(updateBoxSix(int)));
   
   // Connect our expandable buttons
   connect(expandableButtons[0], SIGNAL(clicked()), this, SLOT(openWindowOne()));
   connect(expandableButtons[1], SIGNAL(clicked()), this, SLOT(openWindowTwo()));
   connect(expandableButtons[2], SIGNAL(clicked()), this, SLOT(openWindowThree()));
   connect(expandableButtons[3], SIGNAL(clicked()), this, SLOT(openWindowFour()));
   connect(expandableButtons[4], SIGNAL(clicked()), this, SLOT(openWindowFive()));
   connect(expandableButtons[5], SIGNAL(clicked()), this, SLOT(openWindowSix()));
}

ProcessorWindow::~ProcessorWindow()
{
}

void ProcessorWindow::updateBoxOne(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox == -1)
      {
	 if ((currentAmount + itemPrices[0]) > budgetAmount)
	 {
	    QMessageBox msgBox;
	    msgBox.setText("Did you look at your budget?");
	    msgBox.exec();
	    emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
	    boxOptions[0]->setCheckState(Qt::Unchecked);
	 }
	 else
	 {
	    emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
	    currentlyCheckedBox = 0;
	 }
	    
      }
      else if (currentlyCheckedBox != 0)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
	 
	 if ((currentAmount + itemPrices[0]) > budgetAmount)
	 {
	    QMessageBox msgBox;
	    msgBox.setText("Did you look at your budget?");
	    msgBox.exec();
	    emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
	    boxOptions[0]->setCheckState(Qt::Unchecked);
	 }
	 else
	 {
	    emit sendNewBoxUpdate(itemPrices[0], 0, boxOptions[0]->text());
	    currentlyCheckedBox = 0;
	 }
      }
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[0], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxTwo(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 1 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
      }
      else
         emit sendNewBoxUpdate(itemPrices[1], 0, boxOptions[1]->text());
         
      currentlyCheckedBox = 1;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[1],"");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxThree(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 2 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
      }
      else
         emit sendNewBoxUpdate(itemPrices[2], 0, boxOptions[2]->text());
         
      currentlyCheckedBox = 2;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[2],"");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxFour(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 3 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
      }
      else
         emit sendNewBoxUpdate(itemPrices[3], 0, boxOptions[3]->text());
         
      currentlyCheckedBox = 3;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[3], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxFive(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 4 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
      }
      else
         emit sendNewBoxUpdate(itemPrices[4], 0, boxOptions[4]->text());
         
      currentlyCheckedBox = 4;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[4], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::updateBoxSix(int newState)
{
   // Remove currently checked box and update pricing
   if (newState == 2)
   {
      if (currentlyCheckedBox != 5 && currentlyCheckedBox != -1)
      {
         boxOptions[currentlyCheckedBox]->setCheckState(Qt::Unchecked);
         emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
      }
      else
         emit sendNewBoxUpdate(itemPrices[5], 0, boxOptions[5]->text());
         
      currentlyCheckedBox = 5;
   }
   else if (newState == 0)
   {
      emit sendNewBoxUpdate(0, itemPrices[5], "");
      currentlyCheckedBox = -1;
   }
}

void ProcessorWindow::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
   for (int i = 0; i < 6; ++i)
      if (!(pixMaps[i].isNull()))
         productImages[i]->setPixmap(pixMaps[i].scaled(this->size().width() / 6, this->size().height() / 6, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ProcessorWindow::loadAssets()
{
   // Let's get the location of our images
   QDir workingDirectory(QApplication::applicationFilePath());
   workingDirectory.cdUp();
   workingDirectory.cdUp();
   QString imagesDirectory = workingDirectory.absolutePath() + "/assets/";
   
   // Instantiate our images and put them in pixmaps
   std::vector<QImage> images;
   
   images.push_back(QImage(imagesDirectory + "HighEndAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeAmdCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "HighEndIntelCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "MidRangeIntelCpu.jpeg"));
   images.push_back(QImage(imagesDirectory + "LowRangeIntelCpu.jpeg"));
   
   for (int i = 0; i < 6; ++i)
      pixMaps.push_back(QPixmap(QPixmap::fromImage(images[i])));
}

void ProcessorWindow::openWindowOne()
{
	specWindows[0]->setWindowTitle(boxOptions[0]->text());
	specWindows[0]->show();
	specWindows[0]->activateWindow();
}

void ProcessorWindow::openWindowTwo()
{
	specWindows[1]->setWindowTitle(boxOptions[1]->text());
	specWindows[1]->show();
	specWindows[1]->activateWindow();
}

void ProcessorWindow::openWindowThree()
{
	specWindows[2]->setWindowTitle(boxOptions[2]->text());
	specWindows[2]->show();
	specWindows[2]->activateWindow();
}

void ProcessorWindow::openWindowFour()
{
	specWindows[3]->setWindowTitle(boxOptions[3]->text());
	specWindows[3]->show();
	specWindows[3]->activateWindow();
}

void ProcessorWindow::openWindowFive()
{
	specWindows[4]->setWindowTitle(boxOptions[4]->text());
	specWindows[4]->show();
	specWindows[4]->activateWindow();
}

void ProcessorWindow::openWindowSix()
{
	specWindows[5]->setWindowTitle(boxOptions[5]->text());
	specWindows[5]->show();
	specWindows[5]->activateWindow();
}

void ProcessorWindow::loadSpecs()
{
	specWindows[0]->addWidget(new QLabel("AMD FX-8350 Black Edition Vishera 8-core 4.0 GHz"));
	specWindows[0]->addWidget(new QLabel("Model"));
	specWindows[0]->addWidget(new QLabel("Brand: AMD"));
	specWindows[0]->addWidget(new QLabel("Series: FX-Series"));
	specWindows[0]->addWidget(new QLabel("Name: FX-8350 Black Edition"));
	specWindows[0]->addWidget(new QLabel("CPU Socket Type: Socket AM3+"));
	specWindows[0]->addWidget(new QLabel("Core Name: Vishera"));
	specWindows[0]->addWidget(new QLabel("# of Cores: 8-Core"));
	specWindows[0]->addWidget(new QLabel("# of Threads: 8"));
	specWindows[0]->addWidget(new QLabel("Operating Frequency: 4.0 GHz (4.2Ghz Turbo"));
	specWindows[0]->addWidget(new QLabel("L2 Cache: 4 x 2MB"));
	specWindows[0]->addWidget(new QLabel("L3 Cache: 8MB"));
}

void ProcessorWindow::updateCurrentAmount(double givenAmount)
{
   currentAmount = givenAmount;
}

void ProcessorWindow::updateBudgetAmount(double givenAmount)
{
   budgetAmount = givenAmount;
}
