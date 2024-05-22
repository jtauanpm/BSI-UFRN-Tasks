CREATE OR REPLACE FUNCTION ObterDiasAtrasoAtividade(codigoAtividade INT)
RETURNS INT
LANGUAGE plpgsql
AS
$$
DECLARE
	dias INTEGER;
BEGIN
	SELECT datafim - DATE(CURRENT_DATE AT TIME ZONE 'America/Fortaleza')
	INTO dias
	FROM atividade
	WHERE codigo = codigoAtividade;
	
	RETURN dias;
END;
$$;