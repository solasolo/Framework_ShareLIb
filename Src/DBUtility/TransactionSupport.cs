using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Transactions;

namespace GLEO.DBUtility
{
    public class TransactionBox : IDisposable
    {
        private bool Success;
        private bool Disposed;
        private TransactionScope Scope;
        private BaseDbSupport[] DbList;

        public TransactionBox()
        {
            this.Init();
        }

        public TransactionBox(BaseDbSupport db)
        {
            this.DbList = new BaseDbSupport[1]{db};
            this.Init();
        }

        public TransactionBox(BaseDbSupport[] dbs)
        {
            this.DbList = dbs;
            this.Init();
        }

        ~TransactionBox()
        {
            Dispose(false);
        }

        public void Complete()
        {
            this.DbCommit();
            this.Scope.Complete();

            this.Success = true;
        }

        private void Init()
        {
            this.Disposed = false;
            this.Success = false;

            TransactionOptions opt = new TransactionOptions();
            opt.IsolationLevel = IsolationLevel.ReadCommitted;
            this.Scope = new TransactionScope(TransactionScopeOption.RequiresNew, opt);

            this.DbTransaction();
        }

        private void DbTransaction()
        {
            if (this.DbList != null)
            {
                foreach (BaseDbSupport db in this.DbList)
                {
                    if (db != null)
                    {
                        db.BeginTransaction();
                    }
                }
            }
        }

        private void DbCommit()
        {
            if (this.DbList != null)
            {
                foreach (BaseDbSupport db in this.DbList)
                {
                    if (db != null)
                    {
                        db.CommitTransaction();
                    }
                }
            }
        }
        private void DbRollback()
        {
            if (this.DbList != null)
            {
                foreach (BaseDbSupport db in this.DbList)
                {
                    if (db != null)
                    {
                        db.RollbackTransaction();
                    }
                }
            }
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!this.Disposed)
            {
                if (disposing)
                {
                    if (!this.Success)
                    {
                        this.DbRollback();
                    }

                    this.Scope.Dispose();
                }

                this.Disposed = true;
            }
        }

        #region IDisposable Members

        public void Dispose()
        {
            Dispose(true);

            GC.SuppressFinalize(this);
        }

        #endregion
    }
}
