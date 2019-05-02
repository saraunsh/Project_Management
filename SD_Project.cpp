#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;
class treenode
{
    double price;
    string product;
    treenode *lt;
    treenode *rt;
    public:
    treenode *create(double s,string p)
    {
        treenode *nn=new treenode;
        nn->price=s;
        nn->product=p;
        nn->lt=NULL;
        nn->rt=NULL;
        return nn;
    }
    treenode *insert_r(treenode *root,double item,string name)
    {
        treenode *nn;
        if(root == NULL)
            return root->create(item,name);
        if(item < root->price)
            root->lt=insert_r(root->lt, item,name);
        else
            root->rt=insert_r(root->rt, item,name);
        return root;
    }
    void inorder (treenode *root )
    {
        if(root!=NULL)
        {
            inorder (root -> lt);
            cout<<root->product<<": "<<root->price<<"\n";
            inorder (root -> rt);
        }
    }
    void print(treenode *root)
    {
    	if(root!=NULL)
    	{
    		print(root->rt);
    		cout<<root->product<<": "<<root->price<<"\n";
    		print(root->lt);
    	}
    }
};
    treenode *root;
       int main()
   {
     fstream fout;
    char r;
    int flag=0;
    do
    {
        root=NULL;
        char op;
        do
        {
            if(flag==0)
            {
                int n;
                cout<<"\n************************************************";
                cout<<"\nEnter the number of Products to be Entered...: ";
                cin>>n;
                double a[n];
                string b[n];
                cout<<"\nEnter the Products:\n";
                cout<<"\n************************************************";
                for(int i =0;i<n;i++)
                {
                    cout<<"\nEnter the product name:\n";
                    cin>>b[i];
                    cout<<"\nEnter the price of product:\n";
                    cin>>a[i];
                    root=root->insert_r(root,a[i],b[i]);
                    fout.open("sample.txt",ios::app);
                    fout<<b[i]<<": "<<a[i]<<"\n";
                    fout.close();
                    
                }
                flag=1;
            }
            int c;
            cout<<"\n 1.Insert \n 2.Sort the Products from Low to High Price.  \n 3.Sort the Products from High to Low Price. \n";
            cout<<"\nEnter your choice: ";
            cin>>c;
            switch(c)
            {
                case 1: {
                            double item;
                            string name;
                            cout<<"\nEnter the product name :\n";
                            cin>>name;
                            cout<<"\nEnter price: \n";
                            cin>>item;
                            root=root->insert_r(root, item,name);
                            fout.open("sample.txt",ios::app);
                            fout<<name<<": "<<item<<"\n";
                            fout.close();
                            
                        }
                        break;
                case 2: {
                            root->inorder(root);
                        }
                        break;
                case 3:{
                	        root->print(root);
                       }
                       break;
                default:cout<<"Invalid\n";
        }
        cout<<"Do you wish to continue?(y/n): ";
        cin>>op;
        }while(op=='y' || op=='Y');
    }while(r=='n' || r=='N');
    
    return 0;
}
