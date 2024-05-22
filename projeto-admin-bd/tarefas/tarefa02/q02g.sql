CREATE OR REPLACE FUNCTION AtividadesProjetoPorFuncionario(codigoFunc INT, codigoProjeto INT)
RETURNS INT
LANGUAGE plpgsql
AS
$$
DECLARE
	quantidade INTEGER;
BEGIN
	SELECT COUNT(a.codigo)
	INTO quantidade
	FROM projeto p
		JOIN membro m ON p.equipe = m.codequipe
		JOIN atividade_membro am ON am.codmembro = m.codigo
		JOIN atividade a ON am.codatividade = a.codigo
	WHERE p.codigo = codigoProjeto AND m.codfuncionario = codigoFunc;
	
	RETURN quantidade;
END;
$$;