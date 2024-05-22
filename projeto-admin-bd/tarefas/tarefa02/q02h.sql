CREATE OR REPLACE FUNCTION porcentagem_atividades_func_proj(codigoFunc INT, codigoProjeto INT)
RETURNS DECIMAL
LANGUAGE plpgsql
AS
$$
DECLARE
	porcentagem DECIMAL;
BEGIN
	SELECT
		ROUND(
			AtividadesProjetoPorFuncionario(codigoFunc, codigoProjeto)::decimal/COUNT(ap.codatividade) * 100,
			2)
    INTO porcentagem
    FROM projeto p
		JOIN atividade_projeto ap ON ap.codprojeto = p.codigo
	WHERE p.codigo = codigoProjeto
	GROUP BY p.codigo;
	
	RETURN porcentagem;
END;
$$;