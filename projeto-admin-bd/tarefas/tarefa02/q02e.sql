CREATE OR REPLACE FUNCTION ObterDiasAtrasoProjeto(codigoProjeto INT)
RETURNS INT
LANGUAGE plpgsql
AS
$$
DECLARE
	dias INTEGER;
BEGIN
	SELECT datafim - DATE(CURRENT_DATE AT TIME ZONE 'America/Fortaleza')
	INTO dias
	FROM projeto
	WHERE codigo = codigoProjeto;
	
	RETURN dias;
END;
$$;