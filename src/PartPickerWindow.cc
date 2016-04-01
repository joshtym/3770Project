#include <QtGui>
#include "PartPickerWindow.h"

PartPickerWindow::PartPickerWindow()
{
   // Some variable declarations
   bool goodInput = false;
   QString budgetAmountString;
   QVBoxLayout* mainLayout = new QVBoxLayout();
   QHBoxLayout* budgetLayout = new QHBoxLayout();
   QWidget* centralWidget = new QWidget();
   QLabel* budget = new QLabel();
   
   // Variable instantiations
   currentSpent = new QLabel("Current Cost: $0");
   budget->setAlignment(Qt::AlignLeft);
   currentSpent->setAlignment(Qt::AlignRight);
   totalAmount = 0;
   
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
      budget->setText("No budget!");
   else
      budget->setText("Budget: $" + budgetAmountString);
   
   // Create some tab pages to be used
   for (int i = 0; i < 4; ++i)
      tabPages.push_back(new QScrollArea());
   
   // Create our widgets for our parts
   cpuWindow = new ProcessorWindow();
   mbWindow = new MotherboardWindow();
   ramWindow = new RamWindow();
   hddWindow = new HardDriveWindow();
   
   // Set the scroll area widgets
   tabPages[0]->setWidget(cpuWindow);
   tabPages[1]->setWidget(mbWindow);
   tabPages[2]->setWidget(ramWindow);
   tabPages[3]->setWidget(hddWindow);
   
   // Ensure resizability
   tabPages[0]->setWidgetResizable(true);
   tabPages[1]->setWidgetResizable(true);
   tabPages[2]->setWidgetResizable(true);
   tabPages[3]->setWidgetResizable(true);
   
   // Let's name those tabs and add the scroll areas
   tabBar->addTab(tabPages[0], "CPU");
   tabBar->addTab(tabPages[1], "Motherboard");
   tabBar->addTab(tabPages[2], "RAM");
   tabBar->addTab(tabPages[3], "HDD");
   
   // Set the layouts
   budgetLayout->addWidget(budget);
   budgetLayout->addWidget(currentSpent);
   mainLayout->addWidget(tabBar);
   mainLayout->addLayout(budgetLayout);
   
   // Set this to be the central widget and assign our layout
   setCentralWidget(centralWidget);
   centralWidget->setLayout(mainLayout);
   
   connect(cpuWindow, SIGNAL(sendNewBoxUpdate(double, double)), this, SLOT(receiveAmountUpdate(double, double)));
   connect(mbWindow, SIGNAL(sendNewBoxUpdate(double, double)), this, SLOT(receiveAmountUpdate(double, double)));
   connect(ramWindow, SIGNAL(sendNewBoxUpdate(double, double)), this, SLOT(receiveAmountUpdate(double, double)));
   connect(hddWindow, SIGNAL(sendNewBoxUpdate(double, double)), this, SLOT(receiveAmountUpdate(double, double)));
}

bool PartPickerWindow::parseBudgetAmount(QString budgetString)
{
   bool success = false;
   budgetAmount = budgetString.toDouble(&success);
   return success;
}

void PartPickerWindow::receiveAmountUpdate(double newAmount, double oldAmount)
{
   totalAmount = totalAmount + newAmount - oldAmount;
   currentSpent->setText("Current Cost: $" + QString::number(totalAmount));
}
