%{
//Scanner for in lab quiz 1.
//Russ Hurtado
%}

blob1		("xq")+
blob2		[0-9]*("qw")+
junk		.

%%

"my"		return 1000;
"token"		return 1001;
{blob1}		return 1002;
{blob2}		return 1003;
{junk}		return 2000;
")"		return ')';
"+"		return '+';

"//".*		{};

%%


