#include "cprtypes.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>

//class DTMain

DTMain::DTMain()
{
	std::cout<<"DTMain()\n";
	sIdent=NULL;
	pData=NULL;
}

DTMain::DTMain(char* name)
{
	std::cout<<"DTMain("<<name<<")\n";
	sIdent=new char[strlen(name)];
	strcpy(sIdent,name);
	pData=NULL;
}

void DTMain::SetIdent(char* name)
{
	if (sIdent!=NULL) delete[] sIdent;
	sIdent=new char[strlen(name)];
	strcpy(sIdent,name);
}

char* DTMain::DTFullName()
{
	char* n=DTName();
	std::cout<<"DTFullName():\n";
	std::cout<<"DTName()="<<n<<"\n";
	int sIdLen=0;
	if (sIdent==NULL)    std::cout<<"sIdent=NULL\n";
    else
	{
        std::cout<<"sIdent="<<sIdent<<"\n";
        sIdLen=strlen(sIdent);
	}
	char* a=new char[strlen(n)+1+sIdLen];
	if (sIdent!=NULL)
	{
	    strcpy(a,n);
        strcat(a," ");
        strcat(a,sIdent);
	}else
	{
        strcpy(a,n);
	}
	return a;
}

//class DTInt

DTInt::DTInt(char* name) //without memalloc!
{
	std::cout<<"DTInt("<<((name!=NULL)?name:"NULL")<<")\n";
	pData=NULL;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
	size=0;
}

DTInt::DTInt(char*name,int d)
{
	std::cout<<"DTInt("<<((name!=NULL)?name:"NULL")<<", "<<d<<")\n";
	dtmemalloc();
	*((int*)pData)=d;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
}

void DTInt::dtmemalloc()
{
    dtmemfree();
	pData=new (int);
}

void DTInt::dtmemfree()
{
    if (pData!=NULL)
        delete (int*)pData;
    pData=NULL;
}

char* DTInt::DTName()
{
	char* rs=new char[strlen("signed int")];
	strcpy(rs,"signed int");
	return rs;
}

char* DTInt::tostring()
{
    char* tmp=new char[100];
    sprintf(tmp,"%d",*(int*)pData);
	char* rs=new char[strlen(tmp)];
	strcpy(rs,tmp);
	delete[] tmp;
	return rs;
}

//class DTUInt

DTUInt::DTUInt(char* name) //without memalloc!
{
	std::cout<<"DTUInt("<<((name!=NULL)?name:"NULL")<<")\n";
	pData=NULL;
	size=0;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
}

DTUInt::DTUInt(char*name,unsigned int d)
{
	std::cout<<"DTUInt("<<((name!=NULL)?name:"NULL")<<", "<<d<<")\n";
	dtmemalloc();
	*((unsigned int*)pData)=d;
	sIdent=new char[strlen(name)];
	strcpy(sIdent,name);
}

void DTUInt::dtmemalloc()
{
    dtmemfree();
	pData=new (unsigned int);
}

void DTUInt::dtmemfree()
{
    if (pData!=NULL)
        delete (unsigned int*)pData;
	pData=NULL;
}

char* DTUInt::DTName()
{
	char* rs=new char[strlen("unsigned int")];
	strcpy(rs,"unsigned int");
	return rs;
}

char* DTUInt::tostring()
{
    char* tmp=new char[100];
    sprintf(tmp,"%d",*(int*)pData);
	char* rs=new char[strlen(tmp)];
	strcpy(rs,tmp);
	delete[] tmp;
	return rs;
}

//class DTDouble

DTDouble::DTDouble(char* name) //without memalloc!
{
	std::cout<<"DTDouble("<<((name!=NULL)?name:"NULL")<<")\n";
	pData=NULL;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
	size=0;
}

DTDouble::DTDouble(char*name,double d)
{
	std::cout<<"DTDouble("<<((name!=NULL)?name:"NULL")<<", "<<d<<")\n";
	dtmemalloc();
	*((double*)pData)=d;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
}

void DTDouble::dtmemalloc()
{
    dtmemfree();
	pData=new (double);
}

void DTDouble::dtmemfree()
{
    if (pData!=NULL)
        delete (double*)pData;
    pData=NULL;
}

char* DTDouble::DTName()
{
	char* rs=new char[strlen("double")];
	strcpy(rs,"double");
	return rs;
}

char* DTDouble::tostring()
{
    char* tmp=new char[100];
    sprintf(tmp,"%f",*(double*)pData);
	char* rs=new char[strlen(tmp)];
	strcpy(rs,tmp);
	delete[] tmp;
	return rs;
}

//class DTFloat

DTFloat::DTFloat(char* name) //without memalloc!
{
	std::cout<<"DTFloat("<<((name!=NULL)?name:"NULL")<<")\n";
	pData=NULL;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
	size=0;
}

DTFloat::DTFloat(char*name,float d)
{
	std::cout<<"DTFloat("<<((name!=NULL)?name:"NULL")<<", "<<d<<")\n";
	dtmemalloc();
	*((float*)pData)=d;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
}

void DTFloat::dtmemalloc()
{
    dtmemfree();
	pData=new (float);
}

void DTFloat::dtmemfree()
{
    if (pData!=NULL)
        delete (float*)pData;
    pData=NULL;
}

char* DTFloat::DTName()
{
	char* rs=new char[strlen("float")];
	strcpy(rs,"float");
	return rs;
}

char* DTFloat::tostring()
{
    char* tmp=new char[100];
    sprintf(tmp,"%f",*(float*)pData);
	char* rs=new char[strlen(tmp)];
	strcpy(rs,tmp);
	delete[] tmp;
	return rs;
}

//class DTChar

DTChar::DTChar(char* name) //without memalloc!
{
	std::cout<<"DTChar("<<((name!=NULL)?name:"NULL")<<")\n";
	pData=NULL;
	size=0;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
}

DTChar::DTChar(char*name,char d)
{
	std::cout<<"DTChar("<<((name!=NULL)?name:"NULL")<<", "<<d<<")\n";
	dtmemalloc();
	*((char*)pData)=d;
	sIdent=new char[strlen(name)];
	strcpy(sIdent,name);
}

void DTChar::dtmemalloc()
{
    dtmemfree();
	pData=new char;
}

void DTChar::dtmemfree()
{
    if (pData!=NULL)
        delete (char*)pData;
	pData=NULL;
}

char* DTChar::DTName()
{
	char* rs=new char[strlen("char")];
	strcpy(rs,"char");
	return rs;
}

char* DTChar::tostring()
{
	char* rs=new char[2];
	rs[0]=*((char*)pData);
	rs[1]=0;
	return rs;
}

//class DTPtr

DTPtr::DTPtr(char* name) //without memalloc!
{
	std::cout<<"DTUInt("<<((name!=NULL)?name:"NULL")<<")\n";
	pData=NULL;
	size=0;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
}

DTPtr::DTPtr(char*name,char* tp,void* p)
{
	std::cout<<"DTPtr("<<((name!=NULL)?name:"NULL")<<", "<<((tp!=NULL)?tp:"NULL")<<", <pointer>"<<")\n";
	dtmemalloc();
	if (tp!=NULL)
	{
        _tp=new char[strlen(tp)];
        strcpy(_tp,tp);
	}
	pData=p;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
    }
}

DTPtr::DTPtr(char*name,char* tp)
{
	std::cout<<"DTPtr("<<((name!=NULL)?name:"NULL")<<", "<<((tp!=NULL)?tp:"NULL")<<")\n";
	dtmemalloc();
    _tp=new char[strlen(tp)];
    strcpy(_tp,tp);
	pData=NULL;
	if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
    }
}

void DTPtr::dtmemalloc()
{
    dtmemfree();
	pData=new (void**);
}

void DTPtr::dtmemfree()
{
    if (pData!=NULL)
        delete (void**)pData;
	pData=NULL;
}

char* DTPtr::DTName()
{
	char* rs=new char[strlen("void*")];
	strcpy(rs,"void*");
	return rs;
}

char* DTPtr::tostring()
{
    char* rs;
    if (strcmp(_tp,"char")==0)
    {
        rs=new char[strlen((char*)pData)];
        strcpy(rs,(char*)pData);
    } else
    {
        char* tmp=new char[100];
        sprintf(tmp,"%d",*(int*)pData);
        rs=new char[strlen(tmp)];
        strcpy(rs,tmp);
        delete[] tmp;
    }
	return rs;
}

//class DTArray

DTArray::DTArray(char* name,int sz,int c,char* tp) //with memalloc
{
	std::cout<<"DTArray("<<((name!=NULL)?name:"NULL")<<", "<<sz<<", "<<c<<", "<<((tp!=NULL)?tp:"NULL")<<")\n";
	pData=new char[size*c];
	size=size*c;
    size_one=sz;
    count=c;
    type_one=new char[strlen(tp)];
    strcpy(type_one,tp);
    if (name!=NULL)
	{
        sIdent=new char[strlen(name)];
        strcpy(sIdent,name);
	}
}

void DTArray::dtmemalloc()
{
    dtmemfree();
	pData=new char[size_one*count];
}

void DTArray::dtmemfree()
{
    if (pData!=NULL)
        delete[] pData;
	pData=NULL;
}

char* DTArray::DTName()
{
	char* rs;
	sprintf(rs,"array[sz:%i;cnt:%i]",size_one,count);
	return rs;
}

bool DTArray::FillElement(int n,void* buf)
{
    if (n>=count) return false;
    void* p=(char*)pData+(n*size_one);
    memcpy(p,buf,size_one);
    return true;
}

void* DTArray::GetElement(int n)
{
    void* p=(char*)pData+(n*size_one);
    return *(void**)(p);
}

char* DTArray::tostring()
{
    std::string st;
    DTVar* o;
    for(int i=0;i<count;i++)
    {
        o=ParseDataTypeString(type_one,NULL,NULL);
        (*(DTMain*)(o->T)).pData=GetElement(i);
        st+=(*(DTMain*)(o->T)).tostring();
        if ((i+1)!=count)
            st+=' ';
    }
    char* rs=new char[st.size()+1];
	strcpy(rs,st.c_str());
	rs[st.size()]=0;
	return rs;
}

DTVar* CalculateSum2op(DTMain* a,DTMain* b);
DTVar* CalculateDiff2op(DTMain* a,DTMain* b);
//DTVar* CalculateMul2op(DTMain* a,DTMain* b);
//DTVar* CalculateDiv2op(DTMain* a,DTMain* b);


DTVar* CalculateAct2op(DTMain* a,DTMain* b,char c1,char c2)
{
    if ((c1=='+')&&(c2==' '))
    {
        return CalculateSum2op(a,b);
    };
    if ((c1=='-')&&(c2==' '))
    {
        return CalculateDiff2op(a,b);
    };
}

DTVar* CalculateSum2op(DTMain* a,DTMain* b)
{
     //integer
     if ((a->typeoftype()==b->typeoftype())&&(a->typeoftype()==1))
     {
         DTBigIntegerType* k=new DTBigIntegerType(NULL, ((DTIntegerTypes*)a)->toint()+((DTIntegerTypes*)b)->toint());
         return DTVar::CreateNativeDTVarFromDTMain(k);
     };
     //float
     if (((a->typeoftype()==2)&&((b->typeoftype()==1)||(b->typeoftype()==2)))||
         ((b->typeoftype()==2)&&((a->typeoftype()==1)||(a->typeoftype()==2))))
     {
         DTBigFloatType* k=new DTBigFloatType(NULL, ((DTFloatTypes*)a)->tofloat()+((DTFloatTypes*)b)->tofloat());
         return DTVar::CreateNativeDTVarFromDTMain(k);
     };
}

DTVar* CalculateDiff2op(DTMain* a,DTMain* b)
{
     //integer
     if ((a->typeoftype()==b->typeoftype())&&(a->typeoftype()==1))
     {
         DTInt* k=new DTBigIntegerType(NULL, ((DTIntegerTypes*)a)->toint()-((DTIntegerTypes*)b)->toint());
         return DTVar::CreateNativeDTVarFromDTMain(k);
     };
     //float
     if (((a->typeoftype()==2)&&((b->typeoftype()==1)||(b->typeoftype()==2)))||
         ((b->typeoftype()==2)&&((a->typeoftype()==1)||(a->typeoftype()==2))))
     {
         DTBigFloatType* k=new DTBigFloatType(NULL, ((DTFloatTypes*)a)->tofloat()-((DTFloatTypes*)b)->tofloat());
         return DTVar::CreateNativeDTVarFromDTMain(k);
     };
}

/*DTVar* CalculateMul2op(DTMain* a,DTMain* b)
{
     //integer
     if ((a->typeoftype()==b->typeoftype())&&(a->typeoftype()==1))
     {
         DTInt* k=new DTBigIntegerType(NULL, ((DTIntegerTypes*)a)->toint()-((DTIntegerTypes*)b)->toint());
         return DTVar::CreateNativeDTVarFromDTMain(k);
     };
     //float
}

DTVar* CalculateDiv2op(DTMain* a,DTMain* b)
{
     //integer
     if ((a->typeoftype()==b->typeoftype())&&(a->typeoftype()==1))
     {
         DTInt* k=new DTBigIntegerType(NULL, ((DTIntegerTypes*)a)->toint()-((DTIntegerTypes*)b)->toint());
         return DTVar::CreateNativeDTVarFromDTMain(k);
     };
     //float
}*/


void* DoIntInitializeActions(int t,char* sDT,char* sName, rpnlist* data,DTVar* k)
{
    switch(t)
    {
        case 1:k->T=new DTInt(sName);break;
        case 2:k->T=new DTUInt(sName);break;
        case 3:k->T=new DTChar(sName);break;
    }
    if (data!=NULL)
    {
        if (!data->empty())
        {
            ag::stack<DTVar*>* v=CalculateRPN(data);
            DTMain* h=(DTMain*)(v->pop()->T);
            if (h->typeoftype()==1)
                ((DTIntegerTypes*)(k->T))->setint(((DTIntegerTypes*)h)->toint());
            else
            {
                std::string u="Incompatible types: <";
                u+=h->DTName();
                u+="> and <";
                u+=((DTMain*)k->T)->DTName();
                u+=">";
                char* cstr = new char [u.size()+1];
                strcpy (cstr, u.c_str());
                throw cstr;
            }
            delete v;
        }else
        {
            ((DTIntegerTypes*)(k->T))->setint(0);
        }
    };
};

void* DoDoubleInitializeActions(int t,char* sDT,char* sName, rpnlist* data,DTVar* k)
{
    switch(t)
    {
        case 1:k->T=new DTFloat(sName);break;
        case 2:k->T=new DTDouble(sName);break;
    }
    if (data!=NULL)
    {
        if (!data->empty())
        {
            ag::stack<DTVar*>* v=CalculateRPN(data);
            DTMain* h=(DTMain*)(v->pop()->T);
            if (h->typeoftype()<=2)
            {
                switch(h->typeoftype())
                {
                    case 1:((DTFloatTypes*)(k->T))->setfloat(((DTIntegerTypes*)h)->toint());break;
                    case 2: ((DTFloatTypes*)(k->T))->setfloat(((DTFloatTypes*)h)->tofloat());break;
                }
            }
            else
            {
                std::string u="Incompatible types: ";
                u+=h->DTName();
                u+="and ";
                u+=((DTMain*)k->T)->DTName();
                throw u.c_str();
            }
            delete v;
        }else
        {
            ((DTFloatTypes*)(k->T))->setfloat(0);
        }
    };
};

DTVar* ParseDataTypeString(char* sDT,char* sName, rpnlist* data)
{
    try{

        DTVar* k=new DTVar;
        std::cout<<"sDT: "<<sDT<<"\n";
        if (sDT[strlen(sDT)-1]=='*')
        {
            std::cout<<sDT<<" is pointer\n";
            char* ss=new char[strlen(sDT)];
            strcpy(ss,sDT);
            ss[strlen(ss)-1]=0;
            k->dtet=dtetPointer;
            //k->T=ParseDataTypeString(ss,sName,data);
            k->T=new DTPtr(NULL,ss);
            return k;
        }
        std::cout<<sDT<<" is native data\n";
        k->dtet=dtetNative;
        if (strcmp(sDT,"signed int")==0)
        {
            DoIntInitializeActions(1,sDT,sName,data,k);
        }else
        if (strcmp(sDT,"unsigned int")==0)
        {
            DoIntInitializeActions(2,sDT,sName,data,k);
        }else
        if (strcmp(sDT,"char")==0)
        {
            DoIntInitializeActions(3,sDT,sName,data,k);
        }else
        if (strcmp(sDT,"float")==0)
        {
            DoDoubleInitializeActions(1,sDT,sName,data,k);
        }else
        if (strcmp(sDT,"double")==0)
        {
            DoDoubleInitializeActions(2,sDT,sName,data,k);
        }else

        {
            char* K=new char[strlen("parsing: undeclarated typename: ")+strlen(sDT)];
            strcpy(K,"parsing: undeclarated typename: ");
            strcat(K,sDT);
            throw K;
        }
        std::cout<<"Parsing DT finished\n";
        return k;
    }catch(char* o)
    {
        std::cout<<"(ERROR) "<<o<<"\n";
    }
    catch(...)
    {
        std::cout<<"(UERROR)\n";
    }
}