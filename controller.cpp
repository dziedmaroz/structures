#include "controller.h"

void control (char* scriptfilename)
{
	FILE* fctrl = fopen (scriptfilename,"r");
	if (!fctrl) 
	{
		printf ("CONTROLL_ERR: Can't find script|%s|\n",scriptfilename);
		return;
	}
	int actSize=0;
	while (!feof(fctrl))
	{
		char* tmpS = new char [500];
		fgets(tmpS,500,fctrl);
		tmpS[strlen(tmpS)-1]='\0';
		if (tmpS[0]!='#' && strlen(tmpS)!=0)
			actSize++;
	}
	rewind (fctrl);

	Action* actions = new Action [actSize];
	int line=0;
	int ind=0;	
	while (!feof(fctrl))
	{
		char act[8];
		fscanf(fctrl,"%s",&act);
		line++;
		if (act[0]!='#')
		{
			if (!strcmp (act,"TYPE"))
			{
				actions[ind].keyWrd=TYPE;				 
				fscanf(fctrl,"%s",&actions[ind].textParam);
				actions[ind].intParam=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}
			if (!strcmp (act,"MKNEW"))
			{
				actions[ind].keyWrd=MKNEW;				 
				fscanf(fctrl,"%d",&actions[ind].intParam);
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (!strcmp (act,"LOAD"))
			{
				actions[ind].keyWrd=LOAD;				 
				fscanf(fctrl,"%s",&actions[ind].textParam);
				actions[ind].intParam=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (!strcmp (act,"PRINT"))
			{
				actions[ind].keyWrd=PRINT;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (!strcmp (act,"FPRINT"))
			{
				actions[ind].keyWrd=FPRINT;				 
				fscanf(fctrl,"%s",&actions[ind].textParam);
				actions[ind].intParam=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}
			
			if (!strcmp (act,"SORT"))
			{
				actions[ind].keyWrd=SORT;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (!strcmp (act,"POP"))
			{
				actions[ind].keyWrd=POP;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (!strcmp (act,"PRINTPOP"))
			{
				actions[ind].keyWrd=PRINTPOP;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (!strcmp (act,"PUSH"))
			{
				actions[ind].keyWrd=PUSH;				 				
				actions[ind].intParam=NULL;
				fgets(actions[ind].textParam,100,fctrl);
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}
			printf ("CTRL_ERR: Can't parse this line [%d]\n",line);
		}
	}
	if (!strcmp("stud",actions[0].textParam)) dealStudContainer (actions+1,actSize-1);
	delete [] actions;
	return;
}

void dealStudContainer (const Action* actionList, int actSize)
{
	StudContainer obj (0);
	for (int i=0;i<actSize;i++)
	{
		switch (actionList[i].keyWrd)
		{
		    case TYPE: break;
		    case MKNEW:
			{
			    StudContainer tmp (actionList[i].intParam);
			    obj = tmp;
			    break;
			}
		    case LOAD:
			    {
			       char* tmpS = new char [50];
			       strcpy(tmpS,actionList[i].textParam);
			       FILE* fin = fopen (tmpS,"r");
			       printf ("$%s$\n",actionList[i].textParam);
			       delete []tmpS;
			       while (!feof(fin))
			       {
				    Student tmp;
				    fscanf (fin,"%s %d %lf",&tmp.name,&tmp.num,&tmp.grade);
				    obj.insert (tmp);
			       }
//			       fclose (fin);

			       break;
			    }
		    case PRINT:
			    {
				    obj.print();
				    break;
			    }
		    case POP:case PRINTPOP:
			{
			    printf ("STUD_ERR: POP not defined for StudContainer\n");
			    break;
			}
		    case SORT:
			{
			    obj.sortByName ();
			    break;
			}
		    case RM:
			{
			   char* tmpS = new char [50];
			   strcpy(tmpS,actionList[i].textParam);
			   obj.remove (tmpS);
			   delete [] tmpS;
			    break;
			}
		    case PUSH:
			{
			    printf ("Aha, pushin'-pushin'\n");
			    break;
			}
		}
	}
}
