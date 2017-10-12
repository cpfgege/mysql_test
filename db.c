#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DB_HOST "127.0.0.1"
#define DB_USER 	"root"
#define DB_PASS 	"123456"
#define DB_DB 		"AlgReturndb2"

//int main(){
//
//    MYSQL mysql;
//    mysql_init(&mysql);
//
//    MYSQL *conn = mysql_real_connect(&mysql, DB_HOST, DB_USER, DB_PASS, DB_DB, 0, 0, 0);
//
//    if(conn == NULL){
//
//        printf("Connection Failed");
//        return 1;
//
//    }
//
//    printf("Connection Successed");
//    return 0;
//}
int main()
{
  MYSQL my_connecyion;
  int res;

  mysql_init(&my_connecyion);

  if(mysql_real_connect(&my_connecyion,DB_HOST, DB_USER, DB_PASS, DB_DB,0,NULL,0))
  {
	  printf("Connection success\n");

	//执行SQL语句
	//res = mysql_query(&my_connecyion,"INSERT INTO children(fname,age) VALUES('Annn',3)");
//	  res = mysql_query(&my_connecyion,"REPLACE  children(fname,age) VALUES('Annn',3)");
//	if(!res)
//		printf("Inserted %lu rows\n",(unsigned long)mysql_affected_rows(&my_connecyion));
//	else
//		fprintf(stderr,"Insert error %d : %s \n",mysql_errno(&my_connecyion),mysql_error(&my_connecyion));

	char query[256];
	strcpy(query,"select user_set_space , installation_space ,valid_space_bitmap,ParkingLine_auto_manual_flag,ParkingLine1_manual_setup,"
			"ParkingLine2_manual_setup,ParkingLine3_manual_setup from AiSettingTable where sn=6666666666");
	//STRINSERT(1);
	int t=mysql_real_query(&my_connecyion,query,(unsigned int)strlen(query));//执行指定为计数字符串的SQL查询。
	if(t)
	{
		printf("mysql_real_query err: %s",mysql_error(&my_connecyion));
	}

	MYSQL_RES *res1;
	res1=mysql_store_result(&my_connecyion);//检索完整的结果集至客户端。
	MYSQL_ROW row;
//	while(row = mysql_fetch_row(res1))
	{

		row = mysql_fetch_row(res1)
		for(t=0;t<mysql_num_fields(res1);t++)
		{
			printf("%s\n" ,row[t]);

		}

	}
	mysql_free_result(res1);//释放结果集使用的内存。

	mysql_close(&my_connecyion);
  }
  else{
	  fprintf(stderr,"Connection failed\n");
	  if(mysql_errno(&my_connecyion))
	  fprintf(stderr,"Connection error %d : %s\n",mysql_errno(&my_connecyion),mysql_error(&my_connecyion));
  }

  return 0;
}


