.explain ON
.header ON
-- Add/remove entries in a SQL data table
insert into phone values('Tokugawa Ieyasu', '+81-(0)1-SHOUGUN1');
update phone set phone = '+1-800-BEER-BEER' where name = 'John Adams';
delete from phone where name like 'George%';     
-- Select all phone table contents and display
.width 8 20 20
select rowid,* from phone;

