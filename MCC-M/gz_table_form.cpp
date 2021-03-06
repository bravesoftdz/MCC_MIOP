//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <DateUtils.hpp>
//#include "gz_table_settings.h"

#include "gz_table_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgz_table_frm *gz_table_frm;
//---------------------------------------------------------------------------
AnsiString RsMks[8]; //������ ������ �� ���
int Day;             //���� ������
AnsiString days[] = { "�����������", "�����������", "�������", "�����", "�������", "�������", "�������" };

//Only for test - DEBGGER
AnsiString TestDate="19.09.19";
AnsiString TestText="���� ��-12";

//���� ����� � ������ �� ��� ��������
AnsiString ZARYA_LAUNCH_DATE="20.11.98";
AnsiString ZVEZDA_LAUNCH_DATE="12.07.00";
AnsiString PIRS_LAUNCH_DATE="15.09.01";
AnsiString POISK_LAUNCH_DATE="10.11.09";
AnsiString RASSVET_LAUNCH_DATE="14.05.10";
AnsiString TK_LAUNCH_DATE[4];

// ���������� ����-�����
AnsiString DateString;  //��������� ����
AnsiString TimeStringM; //Moscow
AnsiString TimeStringH; //Houston
AnsiString TimeStringG; //GMT
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall Tgz_table_frm::Tgz_table_frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tgz_table_frm::DMB_timerTimer(TObject *Sender)    //������ 1000 ��
{
RsMks[5]="/ \""+TestText+"\" ";  // ������ ������� � ������
RsMks[6]="/ \""+TestText+"\" ";  // ������ ������� � ������
RsMks[7]="/ \""+TestText+"\" ";  // ������ ������� � ������

Day = DayOfWeek(Now());                             //������� ���� ������
day_name->Caption=days[Day-1];                      //�������� ������ ���
RsMksString->Caption="�� ��� ( \"����\" / \"������\" \"����\" / \"�����\" / \"�������\"";         //������ �� ���
RsMksSOY->Caption=RsMks[5],RsMks[6],RsMks[7];
DayYearN->Caption=IntToStr(DayOfTheYear(Now()));    //����� ����
date_string->Caption=DateString;                    //����� ���� ���������
DateString = FormatDateTime("mm/dd/yy", Now());     //�������������� ���� ��-��-��
TimeStringM = FormatDateTime("hh/nn/ss", Now());     //�������������� ������� ��-��-�� ��� ���
TimeStringG = FormatDateTime("hh/nn/ss", Now());     //�������������� ������� ��-��-�� ��� GMT  !!!����������
dmt->Caption=TimeStringM;                            //����� ������� ����������
obj_data->Caption=IntToStr(DaysBetween(ZARYA_LAUNCH_DATE,Now())+1);     //����� ������ ��������
obj_data2->Caption=IntToStr(DaysBetween(ZVEZDA_LAUNCH_DATE,Now())+1);
obj_data3->Caption=IntToStr(DaysBetween(PIRS_LAUNCH_DATE,Now())+1);
obj_data4->Caption=IntToStr(DaysBetween(POISK_LAUNCH_DATE,Now()));
obj_data5->Caption=IntToStr(DaysBetween(RASSVET_LAUNCH_DATE,Now()));
GrinT->Caption=TimeStringG;
hu_t->Caption=TimeStringM;
scsc->Left=RsMksSOY->Left+RsMksSOY->Width;
kz_time->Caption=RsMksSOY->Width;
}
//---------------------------------------------------------------------------


