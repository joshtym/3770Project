#include <QtGui>
#include "InfoTab.h"

InfoTab::InfoTab()
{
   // The main layout
   QVBoxLayout* mainLayout = new QVBoxLayout();
   
   // Variable instantiations
   
   // Ensure a starting empty vector
   layouts.clear();
   information.clear();

   information.push_back(new QLabel());
   information.push_back(new QLabel());
   information.push_back(new QLabel());
   update_budget = new QPushButton("Update Budget");
   budget_in = new QLineEdit;
   if (budget != -1)
   budget_in->setText(QString::number(budget));
   else
      budget_in->setText("");
   
   

   
   information[0]->setText("Budget is shown in the bottom left corner as well as the current amount spent is shown in the bottom right. Individual part selections will be limited based on the budget set and those products whose selection will exceed the set budget will not be dislpayed in the selection tabs");
   
   information[1]->setText("Displayed parts will be limited based on compatibility with parts selected prior.This particularly concerns the CPU and Mother board components of the selection ");
   
   information[2] ->setText("When all parts have been selected they may be confirmed within the confirmation tab. This clears the selected components within each of the tabs and resets the program to its initial state.");
   // set word wrap for the labels
   information[0]->setWordWrap(true);
   information[1]->setWordWrap(true);
   information[2]->setWordWrap(true);
   // add boxes to layouts and set 
   layouts.push_back(new QHBoxLayout());
   layouts.push_back(new QHBoxLayout());
   layouts.push_back(new QHBoxLayout());
   layouts.push_back(new QHBoxLayout());
      
   
   layouts[0]->addWidget(information[0]);
   layouts[1]->addWidget(budget_in);
   layouts[1] -> addWidget(update_budget);
   layouts[2]->addWidget(information[1]);
   layouts[3]->addWidget(information[2]);
   
   mainLayout->addLayout(layouts[0]);
   mainLayout->addLayout(layouts[1]);
   mainLayout->addLayout(layouts[2]);
   mainLayout->addLayout(layouts[3]);
   
   
   this->setLayout(mainLayout);

   // set connections

   connect(update_budget, SIGNAL(clicked()), this, SLOT(budget_submission()));
   connect(budget_in, SIGNAL(textChanged(const QString &)), this, SLOT(text_change(const QString &)));
   
   
   
}

InfoTab::~InfoTab()
{
   
}


void InfoTab::resizeEvent(QResizeEvent* resizeEvent)
{
   // Handle the resize of the window for the assets
   
}

void InfoTab::updateBudget(double budg)
{
   budget = budg;
   if (budget != -1)
      budget_in->setText(QString::number(budget));
   else
      budget_in->setText("");

}

void InfoTab::budget_submission()
{
   QMessageBox msgBox;
   msgBox.setText("The Budget has been modified.");
   msgBox.setInformativeText("This will remove all part selections present. Continue?");
   msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
   msgBox.setDefaultButton(QMessageBox::Cancel);
   int ret = msgBox.exec();
   switch (ret){
      case QMessageBox::Ok:
      {
	 emit budgetupdated(budget);
	 break;
      }
      case QMessageBox::Cancel:
      {
	 break;
      }
      defualt:
      break;
   }
      
	 
   // emit signal to update budget throughout the program
   
   
   
}

void InfoTab::text_change(const QString & input)
{
   if (parseBudgetAmount(input) or input == "")
   {
      update_budget->setEnabled(true);
   }
   else
   {
      update_budget->setEnabled(false);
   }

}


bool InfoTab::parseBudgetAmount(QString budgetString)
{
   bool success = false;
   budget = budgetString.toDouble(&success);
   if (budgetString == "")
      budget = -1;
   if (budget < 0)
      success = false;
   return success;
}
//
