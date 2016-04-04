#include <QtGui>
#include "InfoWindow.h"

InfoWindow::InfoWindow()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Variable instantiations
   
   // Ensure a starting empty vector
   layouts.clear();
   information.clear();
   updateBudgetButton = new QPushButton("Update Budget");
   budgetIn = new QLineEdit();
   
   // Set our budgetString
   if (budget != -1)
      budgetIn->setText(QString::number(budget));
   else
      budgetIn->setText("");
      
   // Instantiate our vector
   for (int i = 0; i < 3; ++i)
   {
      information.push_back(new QLabel());
      information[i]->setWordWrap(true);
   }
   
   // Update our information panel
   information[0]->setText("Budget is shown in the bottom left corner as well as the current amount spent is shown in the bottom right. Individual part selections will be limited based on the budget set and those products whose selection will exceeed the budget will display a message and will not be able to be selected. The budget may be updated through the below form. Updating the budget will clear all prior selections.");
   information[1]->setText("Displayed parts will be limited based on compatibility with parts selected prior. Those parts that are incompatible with prior selected parts will be greyed out and unable to be selected. This particularly concerns the CPU and Motherboard components of the selection process.");
   information[2] ->setText("When all parts have been selected they may be viewed within the confirmation tab. This tab also allows for confirmation of the selected parts and finalization the order. Finalizing the order clears the selected components within each of the tabs.");
   
   // Add boxes to layouts and set 
   for (int i = 0; i < 4; ++i)
      layouts.push_back(new QHBoxLayout());
   
   // Add our widgets to our layout
   layouts[0]->addWidget(information[0]);
   layouts[1]->addWidget(budgetIn);
   layouts[1]->addWidget(updateBudgetButton);
   layouts[2]->addWidget(information[1]);
   layouts[3]->addWidget(information[2]);
   
   // Add the layouts to the main layout
   mainLayout->addLayout(layouts[0]);
   mainLayout->addLayout(layouts[1]);
   mainLayout->addLayout(layouts[2]);
   mainLayout->addLayout(layouts[3]);
   
   // Set the main layout
   this->setLayout(mainLayout);

   // Set connections
   connect(updateBudgetButton, SIGNAL(clicked()), this, SLOT(budgetSubmission()));
   connect(budgetIn, SIGNAL(textChanged(const QString &)), this, SLOT(textChange(const QString &)));
}

InfoWindow::~InfoWindow()
{
}

void InfoWindow::updateBudget(double givenBudget)
{
   // Assign our budget to our given budget
   budget = givenBudget;
   
   // Assign the string dependent on what the value is
   if (budget != -1)
      budgetIn->setText(QString::number(budget));
   else
      budgetIn->setText("");

}

void InfoWindow::budgetSubmission()
{
   // Create a message box to submit when submitting a new budget
   QMessageBox msgBox;
   msgBox.setText("The Budget has been modified.");
   msgBox.setInformativeText("This will remove all part selections present. Continue?");
   msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
   msgBox.setDefaultButton(QMessageBox::Cancel);
   int optionSelected = msgBox.exec();
   
   // Handle the case for which option is chosen
   switch (optionSelected)
   {
      case QMessageBox::Ok:
         emit budgetUpdated(budget);
         break;
      case QMessageBox::Cancel:
      default:
         break;
   }
}

void InfoWindow::textChange(const QString & input)
{
   // Handle a text change and update depending on whether we have a valid input
   if (parseBudgetAmount(input) || input == "")
      updateBudgetButton->setEnabled(true);
   else
      updateBudgetButton->setEnabled(false);
}


bool InfoWindow::parseBudgetAmount(QString budgetString)
{
   // Assign the budgetString
   // Will return true if it successfully parses and is greater than -1
   bool success = false;
   budget = budgetString.toDouble(&success);
   
   if (budgetString == "")
      budget = -1;
   if (budget < 0)
      success = false;
      
   return success;
}
