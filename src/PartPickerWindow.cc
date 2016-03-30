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
   QLabel* currentSpent = new QLabel("Current Cost: $0");
   budget->setAlignment(Qt::AlignLeft);
   currentSpent->setAlignment(Qt::AlignRight);
   
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
   
   // Set the scroll area widgets
   tabPages[0]->setWidget(new ProcessorWindow());
   tabPages[1]->setWidget(new MotherboardWindow());
   
   // Ensure resizability
   tabPages[0]->setWidgetResizable(true);
   tabPages[1]->setWidgetResizable(true);
   
   // Let's name those tabs and add the scroll areas
   tabBar->addTab(tabPages[0], "CPU");
   tabBar->addTab(tabPages[1], "Motherboard");
   
   // Set the layouts
   budgetLayout->addWidget(budget);
   budgetLayout->addWidget(currentSpent);
   mainLayout->addWidget(tabBar);
   mainLayout->addLayout(budgetLayout);
   
   // Set this to be the central widget and assign our layout
   setCentralWidget(centralWidget);
   centralWidget->setLayout(mainLayout);
}

bool PartPickerWindow::parseBudgetAmount(QString budgetString)
{
   bool success = false;
   budgetAmount = budgetString.toDouble(&success);
   return success;
}
