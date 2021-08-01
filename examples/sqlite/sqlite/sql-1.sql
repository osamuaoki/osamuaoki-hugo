.explain ON
.header ON
-- Generate a SQL data table: phone
create table phone(
	name string NOT NULL, 
	phone string NOT NULL);
insert into phone values('Napoleon Bonaparte', '+33-(0)1.01.01.01.01');
insert into phone values('George Washington', '+1-800-START-USA');
insert into phone values('John Adams', '+1-800-LOVE-BEER');
insert into phone values('Thomas Jefferson', '+1-800-4-FREEDOM');
-- SQLite parameter set and data dump
.width 8 20 20
.show
.schema
.dump phone
-- Select all phone table contents and display
select rowid,* from phone;

