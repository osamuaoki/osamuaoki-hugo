.explain ON
.header ON
-- Generate a SQL test data table: t1
create table t1(a int, b int, c int);
insert into t1 values(1,0,0);
insert into t1 values(2,0,1);
insert into t1 values(3,1,0);
insert into t1 values(4,1,1);
insert into t1 values(5,null,0);
insert into t1 values(6,null,1);
insert into t1 values(7,null,null);
insert into t1 values(null,null,null);
insert into t1 values(null,null,null);
.schema
-- Select all t1 table contents and display
.width 8 8 8 40
select rowid,* from t1;
-- Test SQL case behavior with null
.width 4 8 60
select rowid,a, case when b<>0 then 1 else 0 end from t1;
select rowid,a+10, case when not b<>0 then 1 else 0 end from t1;
select rowid,a+20, case when b<>0 and c<>0 then 1 else 0 end from t1;
select rowid,a+30, case when not (b<>0 and c<>0) then 1 else 0 end from t1;
select rowid,a+40, case when b<>0 or c<>0 then 1 else 0 end from t1;
select rowid,a+50, case when not (b<>0 or c<>0) then 1 else 0 end from t1;
select rowid,a+60, case b when c then 1 else 0 end from t1;
select rowid,a+70, case c when b then 1 else 0 end from t1;
-- What happens when you multiple a NULL by zero?
select rowid,a+80, b*0 from t1;
select rowid,a+90, b*c from t1;
-- What happens to NULL for other operators?
select rowid,a+100, b+c from t1;
-- Check the behavior of NULLs in WHERE clauses
select rowid,a+110 from t1 where b<10;
select rowid,+120 from t1 where not b>10;
select rowid,a+130 from t1 where b<10 OR c=1;
select rowid,a+140 from t1 where b<10 AND c=1;
select rowid,a+150 from t1 where not (b<10 AND c=1);
select rowid,a+160 from t1 where not (c=1 AND b<10);
-- Select null data
select rowid,a+170 from t1 where a isnull;
select rowid,a+180 from t1 where b isnull;
select rowid,a+190 from t1 where c isnull;
-- Test the treatment of aggregate operators
.width 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8
select count(*), count(b), sum(b), avg(b), min(b), max(b) from t1;
-- Check the behavior of NULLs in a DISTINCT query
select distinct b from t1;
-- Check the behavior of NULLs in a UNION query
select b from t1 union select b from t1;
-- NULLs are not considered to be distinct.
create table t2(a int, b int unique);
insert into t2 values(1,1);
insert into t2 values(2,null);
insert into t2 values(3,null);
insert into t2 values(4,1);
.schema
select rowid,* from t2;
-- Remove database tables
drop table t1;
drop table t2;
.schema
--


