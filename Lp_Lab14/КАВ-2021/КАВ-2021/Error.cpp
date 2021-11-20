#include "stdafx.h"
#include "Error.h"

/*
	0-99: ��������� ������
	100-109: ������ ����������
	110-119: ������ �������� � ������ ������
	200-299: ������ ������������ �����������
	300-399: ������ ��������������� �����������
	400-499: ������ �������������� ������������
*/
Error::ERROR errors[ERROR_MAX_ENTRY] = {
	ERROR_ENTRY(0, "������������ ��� ������"),
	ERROR_ENTRY(1, "��������� ����"),
	ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
	ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
	ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),
	ERROR_ENTRY_NODEF10(50),ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),
	ERROR_ENTRY_NODEF10(90),
	ERROR_ENTRY(100, "�������� -in ������ ���� �����"),
	ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
	ERROR_ENTRY(104, "��������� ����� �������� ���������"),
	ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),ERROR_ENTRY_NODEF(108),
	ERROR_ENTRY_NODEF(109),
	ERROR_ENTRY(110, "������ ��� �������� ����� � �������� ����� (-in)"),
	ERROR_ENTRY(111, "������������ ������ � �������� ����� (-in)"),
	ERROR_ENTRY(112, "������ ��� �������� ����� ���������(-log)"),
	ERROR_ENTRY_NODEF(113),ERROR_ENTRY_NODEF(114),ERROR_ENTRY_NODEF(115),ERROR_ENTRY_NODEF(116),
	ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
	ERROR_ENTRY_NODEF10(120),ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
	ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
	ERROR_ENTRY(200, "��������� ������������ ���������� ����� � ������� ������"),
	ERROR_ENTRY(201, "��������� ������������ ������� ������� ������"),
	ERROR_ENTRY(202, "����� �� ������� ������� ������"),
	ERROR_ENTRY(203, "������������� ���������� �������"),
	ERROR_ENTRY(204, "������������� �� ��������"),
	ERROR_ENTRY(205, "������������� ������� �� ����� ���� �������������"),
	ERROR_ENTRY(206, "��������� ������������ ���������� ����� � ������� ���������������"),
	ERROR_ENTRY(207, "��������� ������������ ������� ������� ���������������"),
	ERROR_ENTRY(208, "����� �� ������� ������� ���������������"),
	ERROR_ENTRY(209, "������������ �������"),
	ERROR_ENTRY(210, "����������� ����� �����"),
	ERROR_ENTRY(211, "��������� ����� �����"),
	ERROR_ENTRY(212, "��������� ������������ ����� ��������������"),
	ERROR_ENTRY_NODEF(213),ERROR_ENTRY_NODEF(214),ERROR_ENTRY_NODEF(215),
	ERROR_ENTRY_NODEF(216),ERROR_ENTRY_NODEF(217),ERROR_ENTRY_NODEF(218),ERROR_ENTRY_NODEF(219),
	ERROR_ENTRY_NODEF10(220),ERROR_ENTRY_NODEF10(230),ERROR_ENTRY_NODEF10(240),ERROR_ENTRY_NODEF10(250),
	ERROR_ENTRY_NODEF10(260),ERROR_ENTRY_NODEF10(270),ERROR_ENTRY_NODEF10(280),ERROR_ENTRY_NODEF10(290),
	ERROR_ENTRY(300,"�������� ��������� ���������"),
	ERROR_ENTRY(301,"��������� ��������"),
	ERROR_ENTRY(302,"������ � ���������"),
	ERROR_ENTRY(303,"������ � ���������� �������"),
	ERROR_ENTRY(304,"������ � ���������� ���������� �������"),
	ERROR_ENTRY(305, "������ � ������������"),
	ERROR_ENTRY(306, "�������� ����� �������"),
	ERROR_ENTRY_NODEF(307),ERROR_ENTRY_NODEF(308),ERROR_ENTRY_NODEF(309),
	ERROR_ENTRY_NODEF10(310),ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),
	ERROR_ENTRY_NODEF10(350),ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),ERROR_ENTRY_NODEF10(380),
	ERROR_ENTRY_NODEF10(390),
	ERROR_ENTRY(400, "������ � ������������ ��������"),
	ERROR_ENTRY(401, "������ � ���������� �������"),
	ERROR_ENTRY(402, "������ � ���������� ������� ����������"),
	ERROR_ENTRY(403, "������ � ���������� ������� ���������� (�������� ���-�� ����������)"),
	ERROR_ENTRY(404, "������ � �������� ��� ������ � �������"),
	ERROR_ENTRY(405, "�������������� ������������� � ����������� ����� ������"),
	ERROR_ENTRY(406, "������������� ������������ ���� ������"),
	ERROR_ENTRY(407, "�������������� ���� ������� � ������������� ��������"),
	ERROR_ENTRY(408, "main ������ ���������� �������� ��������"),
	ERROR_ENTRY(409, "������������� ����� ���������� � �������� �������"),
	ERROR_ENTRY(410, "������ � ��������� �����"),
	ERROR_ENTRY(411, "������ � ������� if"),
	ERROR_ENTRY(412, "������� ���������� ������������� ��������"),
	ERROR_ENTRY_NODEF10(420),ERROR_ENTRY_NODEF10(430),ERROR_ENTRY_NODEF10(440),ERROR_ENTRY_NODEF10(450),
	ERROR_ENTRY_NODEF10(460),ERROR_ENTRY_NODEF10(470),ERROR_ENTRY_NODEF10(480),ERROR_ENTRY_NODEF10(490),
	ERROR_ENTRY_NODEF(417),ERROR_ENTRY_NODEF(418),ERROR_ENTRY_NODEF(419),
	ERROR_ENTRY_NODEF100(500),ERROR_ENTRY_NODEF100(600),ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),
	ERROR_ENTRY_NODEF100(900)

};

Error::ERROR Error::geterror(int id) 
{
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		return errors[id];
	}
	return errors[0];
}

Error::ERROR Error::geterrorin(int id, int line, int column) 
{
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		Error::ERROR* temp = &errors[id];
		temp->place = { (short)line, (short)column };
		return *temp;
	}
	return errors[0];
}

Error::ERROR Error::geterrorword(int id, int line, std::string word) {
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		Error::ERROR* temp = &errors[id];
		temp->word = { (short)line, word };
		return *temp;
	}
	return errors[0];
}
