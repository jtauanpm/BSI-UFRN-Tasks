CREATE OR REPLACE FUNCTION ObterIdadeFuncionario(codigoFunc INT)
RETURNS INT
LANGUAGE plpgsql
AS
$$
DECLARE
	idade INTEGER;
BEGIN
	SELECT DATE_PART('YEAR', AGE(datanasc))
	INTO idade
	FROM funcionario
	WHERE codigo = codigoFunc;
	
	RETURN idade;
END;
$$;