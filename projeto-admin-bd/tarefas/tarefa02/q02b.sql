CREATE OR REPLACE FUNCTION ObterMediaIdadeDepartamento(codigoDept INT)
RETURNS FLOAT
LANGUAGE plpgsql
AS
$$
DECLARE
	media FLOAT;
BEGIN
	SELECT AVG(ObterIdadeFuncionario(f.codigo))
	INTO media
	FROM funcionario f
	WHERE f.depto = codigoDept;
	
	RETURN media;
END;
$$;