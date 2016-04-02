#include <QtGui>
#include "PartPickerWindow.h"
#include <iostream>

PartPickerWindow::PartPickerWindow()
{
   // Some variable declarations
   bool goodInput = false;
   QVBoxLayout* mainLayout = new QVBoxLayout();
   QHBoxLayout* budgetLayout = new QHBoxLayout();
   QWidget* centralWidget = new QWidget();
   budget = new QLabel();
   
   // Variable instantiations
   currentSpent = new QLabel("Current Cost: $0");
   budget->setAlignment(Qt::AlignLeft);
   currentSpent->setAlignment(Qt::AlignRight);
   totalAmount = 0;
   productSelectionNames.clear();
   productSelectionPrices.clear();
   
   // Create our widgets for our parts
   infoWindow = new InfoTab();
   cpuWindow = new ProcessorWindow();
   mbWindow = new MotherboardWindow();
   ramWindow = new RamWindow();
   hddWindow = new HardDriveWindow();
   
   // Load up them guns
   for (int i = 0; i < 4; ++i)
   {
      productSelectionNames.push_back("");
      productSelectionPrices.push_back(0);
   }
   
   // Instantiate our tabBar and ensure an empty vector
   tabBar = new QTabWidget();
   tabPages.clear();
   
   // Get the budget from the user
   while (!(goodInput))
   {
      budgetAmountString = QInputDialog::getText(this, tr("Budget Amount"), tr("Please enter your budget for your PC (empty for no budget):"), QLineEdit::Normal, "1000.00", &goodInput);
      
      // Check that it is indeed a good input
      if (goodInput && !(budgetAmountString.isEmpty()))
         goodInput = parseBudgetAmount(budgetAmountString);
   }
   
   // If the budget is empty, then we assume an unlimited budget. Assign the appropriate label
   if (budgetAmountString.isEmpty())
   {
      budget->setText("No budget!");
      cpuWindow->updateBudgetAmount(10000000000);
      mbWindow->updateBudgetAmount(10000000000);
      hddWindow->updateBudgetAmount(10000000000);
      ramWindow->updateBudgetAmount(10000000000);
      infoWindow->updateBudget(-1);
   }
   else
   {
      budget->setText("Budget: $" + budgetAmountString);
      cpuWindow->updateBudgetAmount(budgetAmount);
      mbWindow->updateBudgetAmount(budgetAmount);
      hddWindow->updateBudgetAmount(budgetAmount);
      ramWindow->updateBudgetAmount(budgetAmount);
      infoWindow->updateBudget(budgetAmount);
      
   }
   
   // Create some tab pages to be used
   for (int i = 0; i < 5; ++i)
      tabPages.push_back(new QScrollArea());
   
   // Set the scroll area widgets
   tabPages[0]->setWidget(infoWindow);
   tabPages[1]->setWidget(cpuWindow);
   tabPages[2]->setWidget(mbWindow);
   tabPages[3]->setWidget(ramWindow);
   tabPages[4]->setWidget(hddWindow);
   
   // Ensure resizability
   tabPages[0]->setWidgetResizable(true);
   tabPages[1]->setWidgetResizable(true);
   tabPages[2]->setWidgetResizable(true);
   tabPages[3]->setWidgetResizable(true);
   tabPages[4]->setWidgetResizable(true);
   
   // Let's name those tabs and add the scroll areas
   tabBar->addTab(tabPages[0], "Information");
   tabBar->addTab(tabPages[1], "CPU");
   tabBar->addTab(tabPages[2], "Motherboard");
   tabBar->addTab(tabPages[3], "RAM");
   tabBar->addTab(tabPages[4], "HDD");
   
   // Set the layouts
   budgetLayout->addWidget(budget);
   budgetLayout->addWidget(currentSpent);
   mainLayout->addWidget(tabBar);
   mainLayout->addLayout(budgetLayout);
   
   // Set this to be the central widget and assign our layout
   setCentralWidget(centralWidget);
   centralWidget->setLayout(mainLayout);
   
   connect(cpuWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(mbWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(ramWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(hddWindow, SIGNAL(sendNewBoxUpdate(double, double, QString)), this, SLOT(receiveAmountUpdate(double, double, QString)));
   connect(infoWindow, SIGNAL(budgetupdated(double)), this, SLOT(budget_updated(double)));
}

bool PartPickerWindow::parseBudgetAmount(QString budgetString)
{
   bool success = false;
   budgetAmount = budgetString.toDouble(&success);
   if (budgetAmount < 0)
      success = false;
   return success;
}

void PartPickerWindow::receiveAmountUpdate(double newAmount, double oldAmount, QString deviceName)
{
   totalAmount = totalAmount + newAmount - oldAmount;
   currentSpent->setText("Current Cost: $" + QString::number(totalAmount));
   
   cpuWindow->updateCurrentAmount(totalAmount);
   mbWindow->updateCurrentAmount(totalAmount);
   hddWindow->updateCurrentAmount(totalAmount);
   ramWindow->updateCurrentAmount(totalAmount);
   
   if (newAmount != 0 && oldAmount == 0)
   {
      productSelectionNames[tabBar->currentIndex() - 1] = deviceName;
      productSelectionPrices[tabBar->currentIndex() - 1] = newAmount;
   }
}


void PartPickerWindow::budget_updated(double budget_input)
{
   std::cout << "success: " << budget_input << "\n"; 
   budgetAmount = budget_input;
   budgetAmountString = QString::number(budgetAmount);
   budget->setText("Budget: $" + budgetAmountString);
   cpuWindow->updateBudgetAmount(budgetAmount);
   mbWindow->updateBudgetAmount(budgetAmount);
   hddWindow->updateBudgetAmount(budgetAmount);
   ramWindow->updateBudgetAmount(budgetAmount);
   infoWindow->updateBudget(budgetAmount);
   
   // reset_selection();
   
} 

//void PartPickerWindow::reset_selection()
//{
//   cpuWindow->reset_selection(budgetAmount);
//   mbWindow->reset_selection(budgetAmount);
//   hddWindow->reset_selection(budgetAmount);
//   ramWindow->reset_selection(budgetAmount);


//}
