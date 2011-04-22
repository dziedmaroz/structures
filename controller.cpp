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
		if (tmpS[0]!='#') actSize++;
	}
	rewind (fctrl);

	Action* actions = new Action [actSize];
	int line=0;
	int ind=0;
	while (!feof(fctrl))
	{
		Action tmpAct;
		char act[8];
		fscanf(fctrl,"%s",&act);
		line++;
		if (act[0]!='#')
		{
			if (strcmp (act,"TYPE"))
			{
				actions[ind].keyWrd=TYPE;				 
				fscanf(fctrl,"%s",&actions[ind].textParam);
				actions[ind].intParam=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}
			if (strcmp (act,"MKNEW"))
			{
				actions[ind].keyWrd=MKNEW;				 
				fscanf(fctrl,"%d",&actions[ind].intParam);
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (strcmp (act,"LOAD"))
			{
				actions[ind].keyWrd=LOAD;				 
				fscanf(fctrl,"%s",&actions[ind].textParam);
				actions[ind].intParam=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (strcmp (act,"PRINT"))
			{
				actions[ind].keyWrd=PRINT;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
			}

			if (strcmp (act,"FPRINT"))
			{
				actions[ind].keyWrd=FPRINT;				 
				fscanf(fctrl,"%s",&actions[ind].textParam);
				actions[ind].intParam=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}
			
			if (strcmp (act,"SORT"))
			{
				actions[ind].keyWrd=SORT;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (strcmp (act,"POP"))
			{
				actions[ind].keyWrd=POP;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (strcmp (act,"PRINTPOP"))
			{
				actions[ind].keyWrd=PRINTPOP;				 				
				actions[ind].intParam=NULL;
				actions[ind].textParam[0]=NULL;
				actions[ind].lineNum = line;				
				ind++;
				continue;
			}

			if (strcmp (act,"PUSH"))
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
	delete [] actions;
}

void dealStudContainer (Action* actionList, int actSize)
{
	StudContainer obj (0);
	for (int i=0;i<actSize;i++)
	{
		switch (actionList[i].keyWrd)
		{
			case TYPE: break;
			case MKNEW: obj = StudContainer(actionList[i].intParam);
			case LOAD: 
				{
				   FILE* fin = fopen (actionList[i].textParam,"r");
				   while (!feof(fin))
				   { 
					Student tmp;
					fscanf (fin,"%s %d %lf",&tmp.name,&tmp.num,&tmp.grade);
					obj.insert (tmp);
				   }
				   fclose (fin);
				   break;
				}
			case PRINT:
				{
					obj.print();
				}
		}
	}
}